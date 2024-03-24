# C99 Printf Recreation

*Recreating infamous printf function as described by standard C99.*

> [!CAUTION]
> Copying the content of this repository for your own delivery will grade you a
> `-42` for cheating.

## :closed_book: <samp>C99 limitations</samp>

Please refer to the [fprintf format specification](https://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf#%5B%7B%22num%22%3A571%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C-27%2C816%2Cnull%5D)
for information about supported features.

The current implementation follows strictly the C99 compliance, with the
following known exceptions:

- `long double` (IEEE float 80) support has not been implemented.
- multibyte character (`wchar_t`) are not supported.
- `%e` as not been kept due to its incorrectness.

> [!NOTE]
> Ask requested by the assignment, conversion specifier `B` and `b` from
> c2x standard have been implemented, corresponding to binary format.

### :question: <samp>Invalid format</samp>

In case of invalid format, as specified by C99,our function will treat the given
sequence as regular text and continue.

## :wrench: <samp>Setup</samp>

> [!NOTE]
> To ensure a consistent development environment and to simplify dependency
> management, we strongly recommend using Nix. The project is configured to
> work seamlessly with Nix, providing reproducible builds and a standardized
> development environment.

*If you haven't already, consider installing Nix by following the instructions
on* [nix installation page](https://nixos.org/download).

### :cherry_blossom: <samp>Nix</samp>

You can use the standard nix flakes commands to `clone`, `build`, ... this
project.

```
nix build github:Sigmapitech/myprintf
```

> outputs `libmy.a` containing `my_printf`.

### :paperclip: <samp>Non-nix</samp>

<kbd>0.</kbd> Install the required dependencies

Make sure to have the following dependencies available within your environment:

- The [`Coreutils`](https://www.gnu.org/software/coreutils/coreutils.html) command set, which
 *are expected to exist on every operating system*.
- a recent version of [`Gnu make`](https://www.gnu.org/software/make/manual/make.html) ~4.x.x
- [`GCC`](https://gcc.gnu.org), preferably, version `13.x.x` along the [`GNU C Library`](https://www.gnu.org/software/libc).
- The [`GNU ar`](https://linux.die.net/man/1/ar) archive program, provided by
  [`binutils`](https://www.gnu.org/software/binutils).
- Optionally, [`tput`](https://www.gnu.org/software/termutils/manual/termutils-2.0/html_chapter/tput_1.html)
  command to support colors within the Makefile.
- [`criterion`](https://github.com/Snaipe/Criterion) library to compile tests.
- [`gcovr`](https://github.com/gcovr/gcovr) to retrieve coverage report.

#### <samp>Epitest Docker</samp>

If you want to use the [epitest](https://github.com/Epitech/epitest-docker)
container provided by Epitech, you can use the following command:

```bash
docker run -it --rm -v $(pwd):/home/project -w /home/project epitechcontent/epitest-docker:latest /bin/bash
```

<kbd>I.</kbd> Clone the repository

```bash
git clone https://github.com/Sigmapitech/myprintf.git myprintf
cd myprintf
```

<kbd>II.</kbd> Compile the library

> [!TIP]
> you can `touch .fast` to use parralel building.

```
make
```

To see other available targets, you can use a program such as
[fzf-make](https://github.com/kyu08/fzf-make).

## :bookmark_tabs: <samp>DEVELOPMENT</samp>

if you are using `Nix`, you can access a devShell that you can `develop`
with the project dependencies to build and develop.

```bash
nix develop
nix develop github:Sigmapitech/myrpg
```

### <samp>Using direnv</samp>

You may load the devShell automatically using [direnv](https://direnv.net)
shell integration.

```
echo "use flake" | tee .envrc
direnv allow
```

## :microscope: <samp>TESTING</samp>

A tester is provided to compared the implementation along-side `printf` from
glibc. Test table only features defined behaviour described by the standard.

To run the tests and get a coverage report:

```
make cov
```
