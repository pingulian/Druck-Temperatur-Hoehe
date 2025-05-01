//Länge der Arrays
const int arraylength = 57;

//Stufenzahl
int x[arraylength] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245, 250, 255, 260, 265, 270, 275, 280, 285};
//Luftdruck
float y[arraylength] = {98.87, 98.86, 98.85, 98.84, 98.83, 98.82, 98.81, 98.8, 98.79, 98.78, 98.77, 98.76, 98.75, 98.74, 98.74, 98.73, 98.72, 98.71, 98.7, 98.69, 98.68, 98.67, 98.66, 98.65, 98.64, 98.63, 98.62, 98.61, 98.6, 98.59, 98.58, 98.56, 98.55, 98.54, 98.53, 98.52, 98.51, 98.5, 98.5, 98.49, 98.48, 98.47, 98.46, 98.45, 98.44, 98.43, 98.42, 98.41, 98.4, 98.39, 98.38, 98.37, 98.36, 98.35, 98.34, 98.33, 98.32};
int z = 2;

const int maxerlabweichung = 30; //maximal erlaubte Abweichung (%)

int a = 1; //Exponent für x für print
int b = 1; //Exponent für y für print
int c = 1; //Counter

float xy[arraylength];

float average;
float minWert;
float maxWert;
float maxabweichungnumb;
float abweichung;

void setup() {

  Serial.begin(9600);

  if (z == 1) {
    for (int i = 0; i < arraylength; i++) {
      if (x[i] > 0) {
        y[i] = -log(x[i]) + 3.17;
      } else {
        y[i] = 0; // Fehlerbehandlung
      }
    }
  } else if (z == 2) {
    for (int i = 0; i < arraylength; i++) {
      y[i] = -y[i] + 98.88;
    }
  }



}

void min_max_abw() {
  //Berechnung Durchschnitt
  float summe = 0;
  for (int i = 0; i < arraylength; i++) {
    summe += xy[i];
  }
  average = summe / arraylength;

  //Berechnung Minimum und Maximum
  minWert = xy[0];
  maxWert = xy[0];

  for (int i = 1; i < arraylength; i++) {
    if (xy[i] < minWert) {
      minWert = xy[i];
    }
    if (xy[i] > maxWert) {
      maxWert = xy[i];
    }
  }

  maxabweichungnumb = max(fabs(maxWert - average), fabs(minWert - average));

  abweichung = fabs((maxabweichungnumb / average) * 100); //Abweichung in %
}

void antiproportional() {
  delay(5000);
  if (abweichung < maxerlabweichung) {
        Serial.println("\n\n - x entspricht h (Höhe); y entspricht -P(h) (Luftdruck) + 98,88 - ");

        Serial.print("Durchschnitt von (x ↑");
        Serial.print(a); 
        Serial.print("* y ↑");
        Serial.print(b);
        Serial.print("): ");
        Serial.println(average);


        Serial.print("Maximaler Wert:");
        Serial.println(maxWert);
        Serial.print("Minimaler Wert:");
        Serial.println(minWert);

        Serial.print("\nMaximale Abweichung vom Durchschnitt (Absolute Zahl):");
        Serial.println(maxabweichungnumb);

        Serial.print("Maximale Abweichung vom Durchschnitt (%):");
        Serial.print(abweichung);
        Serial.println("%");

        Serial.print("Maximal zugelassene Abweichung: ");
        Serial.print(maxerlabweichung);
        Serial.println("%");

        Serial.println("\nErgebnis:");
        
        Serial.print("(x ↑");
        Serial.print(a);
        Serial.print("* y ↑");
        Serial.print(b);
        Serial.println(") = konstant (antiproportional)");
        Serial.println("(Die Abweichung vom Durchschnitt überschreitet die maximal zugelassene Abweichung nicht)");
        ende();
    }    
    else {
        Serial.print("\n\n(x ↑");
        Serial.print(a);
        Serial.print("* y ↑");
        Serial.print(b);
        Serial.println(") ist nicht konstant (nicht antiproportional)");
        Serial.println("(Die Abweichung vom Durchschnitt überschreitet die maximal zugelassene Abweichung)");
    }
        
}

void proportional() {
  delay(5000);
  if (abweichung < maxerlabweichung) {
        Serial.println("\n\n - x entspricht h (Höhe); y entspricht -P(h) (Luftdruck) + 98,88 - ");

        Serial.print("Durchschnitt von (x ↑");
        Serial.print(a); 
        Serial.print("/ y ↑");
        Serial.print(b);
        Serial.print("): ");
        Serial.println(average);


        Serial.print("Maximaler Wert:");
        Serial.println(maxWert);
        Serial.print("Minimaler Wert:");
        Serial.println(minWert);

        Serial.print("\nMaximale Abweichung vom Durchschnitt (Absolute Zahl):");
        Serial.println(maxabweichungnumb);

        Serial.print("Maximale Abweichung vom Durchschnitt (%):");
        Serial.print(abweichung);
        Serial.println("%");

        Serial.print("Maximal zugelassene Abweichung: ");
        Serial.print(maxerlabweichung);
        Serial.println("%");

        Serial.println("\nErgebnis:");
        
        Serial.print("(x ↑");
        Serial.print(a);
        Serial.print("/ y ↑");
        Serial.print(b);
        Serial.println(") = konstant (proportional)");
        Serial.println("(Die Abweichung vom Durchschnitt überschreitet die maximal zugelassene Abweichung nicht)");
        ende();
    }    
    else {
        Serial.print("\n\n(x ↑");
        Serial.print(a);
        Serial.print("/ y ↑");
        Serial.print(b);
        Serial.println(") ist nicht konstant (nicht proportional)");
        Serial.println("(Die Abweichung vom Durchschnitt überschreitet die maximal zugelassene Abweichung)");
    }
        
}

void loop() {
  //Antiproportionaler Zusammenhang
    if ((abs(x[1]) > abs(x[arraylength - 1]) and abs(y[1]) < abs(y[arraylength - 1])) or (abs(x[1]) < abs(x[arraylength - 1]) and abs(y[1]) > abs(y[arraylength - 1]))) {
        Serial.print("Antiproportionaler Zusammenhang");
        //xy = x * y;
        for (int i = 0; i < arraylength; i++) {
          xy[i] = x[i] * y[i];
        }
        min_max_abw();
        antiproportional();

        //Was soll passieren, wenn xy nicht konstantt ist (nicht antiproportional)?
        while (true) {
            if ((xy[1] > xy[arraylength - 1] and x[1] < x[arraylength - 1]) or (xy[1] < xy[arraylength - 1] and x[1] > x[arraylength - 1])){ //Antiproportional
                c = c + 1;
                Serial.print("Zusammenhang" + c );
                a = a + 1; //Exponent von x erhöhen
                //xy = xy * x;
                for (int i = 0; i < arraylength; i++) {
                  xy[i] = xy[i] * x[i];
                }
                min_max_abw();
                antiproportional();
        
            } else { //Proportional
                c = c + 1;
                Serial.print("Zusammenhang" + c );
                b = b + 1; //Exponent von y erhöhen
                //xy = xy * y;
                for (int i = 0; i < arraylength; i++) {
                  xy[i] = xy[i] * y[i];
                }
                min_max_abw();
                antiproportional();
            }
        }
    }
    //Proportionaler Zusammenhang
    else {
        Serial.print("Proportionaler Zusammenhang");
        //xy = x / y;
        for (int i = 0; i < arraylength; i++) {
          xy[i] = x[i] / y[i];
        }
        min_max_abw();
        proportional();

        //Was soll passieren, wenn x/y nicht konstantt ist (nicht proportional)?
        while (true) {
            if ((xy[1] > xy[arraylength - 1] and x[1] > x[arraylength - 1]) or (xy[1] < xy[arraylength - 1] and x[1] < x[arraylength - 1])) { //Proportional
                c = c + 1;
                Serial.print("Zusammenhang" + c );
                b = b + 1; //Exponent von y erhöhen
                //xy = xy / y;
                for (int i = 0; i < arraylength; i++) {
                  xy[i] = xy[i] / y[i];
                }
                min_max_abw();
                proportional();

            } else { //Antiproportional
                c = c + 1;
                Serial.print("Zusammenhang" + c );
                a = a + 1; //Exponent von x erhöhen
                //xy = xy * x;
                for (int i = 0; i < arraylength; i++) {
                  xy[i] = xy[i] * x[i];
                }
                min_max_abw();
                proportional();
            }
        }
    }
}

void ende() {
  while (true);
}
