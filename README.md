# Re-Nano ID

A tiny, secure, URL-friendly, unique string ID generator for ReasonML/OCaml,
inspired by [`ai/nanoid`](https://github.com/ai/nanoid).

```reason
TODO --- CODE SNIPPET EXAMPLE
```

### Why Re-Nano ID?

**Fast**. It's 16% faster than UUID. TODO: Confirm this with OCaml's existing UUID package.

**Safe.** It uses cryptographically strong random APIs
and guarantees a proper distribution of symbols.

**Compact.** It uses a larger alphabet than UUID (`A-Za-z0-9_-`)
and has a similar number of unique IDs in just 21 symbols instead of 36.

See `ai/nanoid`'s [excellent documentation](https://github.com/ai/nanoid/blob/master/README.md#table-of-contents) for more background about random identifier generation and comparisons with UUID v4.

## Usage

TODO: Describe how to use in BuckleScript or Native project

TODO: See the [Rust example](https://github.com/nikolay-govorov/nanoid/blob/master/README.md#usage)'s Usage section for more info about this --- `re-nanoid` will have different configurations that we need to document with explanations and code snippets.

## Use Cases

TODO: Describe use cases --- see this repo's wiki.

## Contributing

TODO: Blurb about contributing

## References (TODO: consider removing before making public)

- https://tech.ahrefs.com/how-to-write-a-library-for-bucklescript-and-native-22f45e5e946d
- https://github.com/ahrefs/hello-native-bucklescript
