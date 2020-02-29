type t;

[@bs.module "crypto"]
external randomFillSync: Buffer.t => Buffer.t = "randomFillSync";

[@bs.module "crypto"] external randomBytes: int => Buffer.t = "randomBytes";
