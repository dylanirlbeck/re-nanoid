open NanoId;

// Test regular
Js.log(nanoid());
Js.log(nanoid());

// Test optional size
Js.log(nanoid(~size=10, ()));
Js.log(nanoid(~size=5, ()));
