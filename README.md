# re-nanoid

A tiny, secure, URL-friendly, unique string ID generator for ReasonML/OCaml,
inspired by [`ai/nanoid`](https://github.com/ai/nanoid).

```reason
open NanoId

let id = nanoid(); // "V1StGXR8_Z5jdHi6B-myT"W
```

### Why re-nanoid?

**Fast**. It's 16% faster than UUID package.

**Safe.** It uses cryptographically strong random APIs
and guarantees a proper distribution of symbols.

**Compact.** It uses a larger alphabet than UUID (`A-Za-z0-9_-`)
and has a similar number of unique IDs in just 21 symbols instead of 36.

See `ai/nanoid`'s [excellent documentation](https://github.com/ai/nanoid/blob/master/README.md#table-of-contents) for more background about random identifier generation and comparisons with UUID v4.

## Installation

### BuckleScript

```
$ yarn add @dylanirlbeck/re-nanoid
```

Then add `@dylanirlbeck/re-nanoid` to your `bs-dependencies` in `bsconfig.json`

```
{
   ...
   "bs-dependencies": ["@dylanirlbeck/re-nanoid"]
}
```

### Native

Coming soon...

## Usage

> As of now, the following examples work for BuckleScript. The Native library
> will be released soon.

### Simple

The main module uses URL-friendly symbols (`A-Za-z0-9_-`) and returns an ID with
21 characters by default, though this size is variable (see below).

```reason
open NanoId;

let id = nanoid(); // "V1StGXR8_Z5jdHi6B-myT"
```

If you want to reduce the ID size (and increase collision probability), you can
pass the size as an argument. You can also increase the ID size (to a maximum of
36).

```reason
open NanoId;

let id = nanoid(~size=10, ()); // "1s_t232nj_"
```

### Custom length or alphabet

Likewise, if you want to use a different alphabet, you can use the
`customAlphabet` function. Note that this function also takes a `size`
parameter.

```reason
open NanoId;

let alphabet = "#$@jasssfaª•¶";
let size = 7;

let nanoid = customAlphabet(~size, ~alphabet, ());

let id = nanoid(); // "jfa##$·"
```

> Note the use of the `()` as the last parameter of the function call.

### Custom random bytes generator

> Note that this function might not work yet.

`customRandom` allows you to create a `nanoid` and replace the default random
bytes generator.

```reason
open NanoId;

let rbg = size: int => {
  // Put generator logic here
};

let nanoid = customRandom(~alphabet="abcdef", ~size=10, rbg, ());

let id = nanoid(); // "fbaefaadeb"
```

## Contributing

Pull requests are welcome!

## Testing

### BucklesScript - Jest

In order to run the tests as they stand currently, open a new terminal window
and run `yarn watch` to re-compile upon Reason file changes. In yet another
window, run `yarn test` to watch for changes to compiled files and re-run the
tests if changes are detected.

### Native - Rely

Native tests do not yet exist, but they should be present soon.

### License

`re-nanoid` is [MIT licensed](https://github.com/dylanirlbeck/re-nanoid/blob/master/LICENSE).

### Other

This library was born out of a project at HackIllinois 2020. See our Devpost submission [here](https://devpost.com/software/re-nanoid#updates)!
