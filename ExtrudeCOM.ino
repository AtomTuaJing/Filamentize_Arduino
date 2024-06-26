String dat;

String rlTempMID_String = "";
String rlTempEND_String = "";
String rpmFan1_String = "";
String rpmFan2_String = "";

void initExtrude() {
  Extrude.begin(9600);
  Serial.println("Extrude started");
}
void getdatFromExtrude() {
  if (Extrude.available() > 0) {
    dat = Extrude.readStringUntil('\n');
    rlTempMID_String = getValue(dat, ',', 0);
    rlTempEND_String = getValue(dat, ',', 1);
    rpmFan1_String = getValue(dat, ',', 2);
    rpmFan2_String = getValue(dat, ',', 3);
  }
}

int rlTempMID_Value() {
  return rlTempMID_String.toInt();
}

int rlTempEND_Value() {
  return rlTempEND_String.toInt();
}

int rpm_Fan1() {
  return rpmFan1_String.toInt();
}

int rpm_Fan2() {
  return rpmFan2_String.toInt();
}

void sentData(int m, int e, int f1, int f2, int ex, int vi) {
  Extrude.println(String(m) + "," + String(e) + "," + String(f1) + "," + String(f2) + "," + String(ex) + "," + String(vi));
}

String getValue(String data, char separator, int index)
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
