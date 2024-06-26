void printBinary(int number) {
  int bit0, bit1, bit2, bit3;
  for (int i = 3; i >= 0; i--) {
    if (number & (1 << i)) {
      Serial.print("1,");
      if (i == 3) bit3 = 1;
      else if (i == 2) bit2 = 1;
      else if (i == 1) bit1 = 1;
      else if (i == 0) bit0 = 1;
    } else {
      Serial.print("0,");
      if (i == 3) bit3 = 0;
      else if (i == 2) bit2 = 0;
      else if (i == 1) bit1 = 0;
      else if (i == 0) bit0 = 0;
    }
    delay(10);
  }
//  Serial.println("");
//  Serial.print("bit3: "); Serial.println(bit3);
//  Serial.print("bit2: "); Serial.println(bit2);
//  Serial.print("bit1: "); Serial.println(bit1);
//  Serial.print("bit0: "); Serial.println(bit0);
  if (bit3 == 1) {
    digitalWrite(Color1, HIGH);
  }
  if (bit2 == 1) {
    digitalWrite(Color2, HIGH);
  }
  if (bit1 == 1) {
    digitalWrite(Color3, HIGH);
  }
  if (bit0 == 1) {
    digitalWrite(Color4, HIGH);
  }
  if (bit0 && bit1 && bit2 && bit3 == 0) {
    digitalWrite(Color4, LOW);
    digitalWrite(Color3, LOW);
    digitalWrite(Color2, LOW);
    digitalWrite(Color1, LOW);
  }
}
