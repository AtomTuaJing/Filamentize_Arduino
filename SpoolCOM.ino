String SpoolPercent_String = "";
String dat2;

void initSpool() {
  Spool.begin(9600);
  Serial.println("Spool Start");
}

void getdat2FromSpool() {
  if (Spool.available() > 0) {
    dat2 = Spool.readStringUntil('\n');
    SpoolPercent_String = getValue2(dat2, ',', 0);
  }
}

int SpoolPercent_Value() {
  return SpoolPercent_String.toInt();
}

void sentDataSpool(int m, int e) {
  Spool.println(String(m) + "," + String(e));
}

String getValue2(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1  };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
