type t;

[@bs.val] external allocUnsafe: int => array('a) = "Buffer.allocUnsafe";
