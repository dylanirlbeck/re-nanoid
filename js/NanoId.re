// The type of a Nano ID (hint, it's just string!)
type t = string;

// TODO investigate this type

type uInt8Array = array(int);

[@bs.module "nanoid"] external nanoid: (~size: int=?, unit) => t = "nanoid";

[@bs.module "nanoid"]
external customAlphabet: (~alphabet: string, ~size: int, unit) => t =
  "customAlphabet";

[@bs.module "nanoid"]
external customRandom:
  (
    ~alphabet: string,
    ~size: int,
    ~random: (~bytes: int) => uInt8Array,
    unit
  ) =>
  t =
  "customRandom";

[@bs.module "nanoid"] external urlAlphabet: string = "urlAlphabet";

[@bs.module "nanoid"] external random: (~bytes: int) => uInt8Array = "random";
