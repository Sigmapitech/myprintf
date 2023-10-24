{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
  };

  outputs = { self, nixpkgs }:
    let
      forAllSystems = function:
        nixpkgs.lib.genAttrs [
          "x86_64-linux"
          "aarch64-linux"
        ]
          (system: function nixpkgs.legacyPackages.${system});
    in
    {
      formatter = forAllSystems (pkgs: pkgs.nixpkgs-fmt);

      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
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
      });

      packages = forAllSystems (pkgs: rec {
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

        unit_tests = libmy.overrideAttrs(prev: rec {
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
      });
    };
}
