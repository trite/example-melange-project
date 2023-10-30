# Current issue:

Compiled with problems:
ERROR
Cannot find module '@emotion/css'
webpackMissingModule@webpack:///./_build/default/src/output/node_modules/styled-ppx.bs-css-emotion/CssJs.js?:697:50
@webpack:///./_build/default/src/output/node_modules/styled-ppx.bs-css-emotion/CssJs.js?:697:137
./_build/default/src/output/node_modules/styled-ppx.bs-css-emotion/CssJs.js@http://localhost:8080/main.js:415:1
__webpack_require__@http://localhost:8080/main.js:912:33
fn@http://localhost:8080/main.js:1111:21
@webpack:///./_build/default/src/output/src/ReactApp.js?:7:111
./_build/default/src/output/src/ReactApp.js@http://localhost:8080/main.js:470:1
__webpack_require__@http://localhost:8080/main.js:912:33
@http://localhost:8080/main.js:1984:56
@http://localhost:8080/main.js:1986:12
ERROR in ./_build/default/src/output/node_modules/styled-ppx.bs-css-emotion/CssJs.js 3:0-36
Module not found: Error: Can't resolve '@emotion/css' in '/home/trite/git/example-melange-project/_build/default/src/output/node_modules/styled-ppx.bs-css-emotion'


# example-melange-project

A simple project template using [Melange](https://github.com/melange-re/melange)
with [opam](https://opam.ocaml.org/).

If you are looking for a template with esy, check [melange-esy-template](https://github.com/melange-re/melange-esy-template).

## Quick Start

```shell
make init

# In separate terminals:
make watch
make serve
```

When running `make init`, you may encounter an error like this:

```
[ERROR] Could not determine which packages to install for this switch:
  * Missing dependency:
    - melange >= 1.0.0
    no matching version
```

It means `opam` doesn't have the latest packages definitions from the opam-repository. To address this, first run `opam update`, then rerun `make init`.

### React

React support is provided by
[`reason-react`](https://github.com/reasonml/reason-react/). The entry
point of the sample React app is [`src/ReactApp.re`](src/ReactApp.re).

## Commands

In opam / dune projects, our personal preference is to group commonly used commands in a Makefile. This is completely optional.

You can see all available commands by running `make help` or just `make`. Here
are a few of the most useful ones:

- `make init`: set up opam local switch and download OCaml, Melange and
JavaScript dependencies
- `make install`: install OCaml, Melange and JavaScript dependencies
- `make watch`: watch for the filesystem and have Melange rebuild on every
change
- `make serve`: serve the application with a local HTTP server

## JavaScript output

Since Melange compiles source files into JavaScript files, it can be used
for projects on any JavaScript platform - not just the browser.

The template includes two `melange.emit` stanza for two separate apps. This
stanza tells Dune to generate JavaScript files using Melange, and specifies in
which folder the JavaScript files should be placed, by leveraging the `target`
field:
- The React app JavaScript files will be placed in `_build/default/src/output/*`.
- The NodeJS app JavaScript files will be placed in `_build/default/src/node/*`.

So for example, [`src/Hello.ml`](src/Hello.ml) (using OCaml syntax) can be run with
`node`:

```bash
node _build/default/src/node/src/Hello.js
```

Similarly, `_build/default/src/output/src/ReactApp.js` can be passed as entry to a bundler
like Webpack:

```bash
webpack --mode production --entry ./_build/default/src/output/src/ReactApp.js
```
