let rec generateId = (~size, ~alphabet, ~currId="", ~bytes: array('a)) => {
  switch (size) {
  | 0 => currId
  | _ =>
    generateId(
      ~size=size - 1,
      ~alphabet,
      ~currId=currId ++ String.make(1, alphabet.[bytes[size - 1] land 63]),
      ~bytes,
    )
  };
};
