let random = (~bytes) => {
  let buffer = Buffer.allocUnsafe(bytes);
  Crypto.randomFillSync(buffer);
};
