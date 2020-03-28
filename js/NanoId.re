// The type of a Nano ID (hint, it's just string!)
type t = string;

[@bs.module "nanoid"] external nanoid: (~size: int=?, unit) => t = "nanoid";
