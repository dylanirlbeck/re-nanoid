type t;

[@bs.module "crypto"]
external randomFillSync: array('a) => array('a) = "randomFillSync";

[@bs.module "crypto"] external randomBytes: int => array('a) = "randomBytes";
