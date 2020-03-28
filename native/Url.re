let specialChars = "-_";
let numbers = "0123456789";

let lowerCaseAlpha = "abcdefghijklmnopqrstuvwxyz";
let upperCaseAlpha = String.uppercase_ascii(lowerCaseAlpha);

let urlChars = specialChars ++ numbers ++ lowerCaseAlpha ++ upperCaseAlpha;
