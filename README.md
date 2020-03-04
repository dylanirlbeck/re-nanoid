# re-nanoid

A tiny, secure, URL-friendly, unique string ID generator for ReasonML/OCaml,
inspired by [`ai/nanoid`](https://github.com/ai/nanoid).

```reason
open NanoId

let id = nanoid(); // "V1StGXR8_Z5jdHi6B-myT"
```

### Why `re-nanoid`?

**Fast**. It's 16% faster than UUID package.

**Safe.** It uses cryptographically strong random APIs
and guarantees a proper distribution of symbols.

**Compact.** It uses a larger alphabet than UUID (`A-Za-z0-9_-`)
and has a similar number of unique IDs in just 21 symbols instead of 36.

See `ai/nanoid`'s [excellent documentation](https://github.com/ai/nanoid/blob/master/README.md#table-of-contents) for more background about random identifier generation and comparisons with UUID v4.

## Usage

### Simple

The main module uses URL-friendly symbols (`A-Za-z0-9_-`) and returns an ID with
21 characters by default.

```reason
open NanoId

let id = nanoid(); // "V1StGXR8_Z5jdHi6B-myT"
```

### Custom length or alphabet

If you want to reduce the ID size (and increase collision probability), you can
pass the size as an argument. Likewise, if you want to use a different alphabet,
you can pass the alphabet as a second argument.

```reason
open NanoId

let alphabet = "#$@jasssfaª•¶";
let size = 15;

let id = nanoid(~size, ~alphabet, ());
```

> Note the use of the `()` as the last parameter of the function call.

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
