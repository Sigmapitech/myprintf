{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachSystem [ "x86_64-linux" ] (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      rec {
        formatter = pkgs.nixpkgs-fmt;

        devShells = {
          default = pkgs.mkShell {
            hardeningDisable = [ "all" ];
            inputsFrom = pkgs.lib.attrsets.attrValues packages;
            packages = with pkgs; [
              criterion
              gcc13
              gcovr
              glibc
              gnumake
              python310Packages.compiledb
              valgrind
            ];
          };
        };

        packages = rec {
          default = libmy;
          libmy = pkgs.stdenv.mkDerivation rec {
            name = "libmy.a";
            src = ./.;

            makeFlags = [ "CC=${pkgs.gcc13}/bin/gcc" ];
            buildInputs = [ pkgs.gnumake ];

            hardeningDisable = [ "format" "fortify" ];
            enableParallelBuilding = true;

            installPhase = ''
              runHook preInstall

              mkdir -p $out/lib
              cp ${name} $out/lib/${name}

              runHook postInstall
            '';
          };

          unit_tests = libmy.overrideAttrs (prev: rec {
            name = "unit_tests";
            buildInputs = prev.buildInputs ++ [ pkgs.criterion ];
            buildPhase = ''
              runHook preBuild

              make unit_tests NO_COV=1

              runHook postBuild
            '';

            installPhase = ''
              runHook preInstall

              mkdir -p $out/bin
              cp ${name} $out/bin/${name}

              runHook postInstall
            '';

          });
        };
      });
}
