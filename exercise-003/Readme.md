# Übungsaufgabe Nr. 3

Bevor Sie mit der Bearbeitung der ersten Übungsaufgabe starten wollen wir zunächst Ihre ``git`` Kenntnisse vertiefen. In den letzten Vorlesung Terminen haben Sie das Konzept der verschiedenen remotes kennengelernt. Dies wollen wir nun vertiefen. Am Ende verfügt Ihre lokale Arbeitskopie über mindestens zwei remotes. Aber zunächst alles der Reihe nach.

**WICHTIG:** Diese Übungsaufgabe soll einzeln und nicht in Gruppen erfolgen.

## Konfliktfrei

Aller Anfang ist schwer. Um sich das Leben nicht unnötig schwer zu machen sollten Sie den master Branch zunächst nicht ändern und jeweils immer nur die Änderungen aus dem allgemeinen Repository pullen. Das klare Ziel am Anfang ist es keine Konflikte zu provozieren.


**ACHTUNG:** Prüfen Sie ob ``origin`` Ihrer projekt URL entspricht! In dieser darf ``graugans`` nicht auftauchen!


## Anlegen der Branches

Bevor Sie anfangen Quellcode zu schreiben erzeugen sie zunächst eine Kopie des Branches für die erste Übungsaufgabe. Zunächst müssen wir allerdings die lokale Kopie unseres Repository mit `upstream` und Ihrem `origin` synchronisieren.  

```
git fetch --all
git checkout -b solution-003 upstream/exercise-003
```

Sie können mit dem Kommando ``git branch -a`` prüfen ob dies erfolgreich war:

```
  master
* solution-003
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
  remotes/upstream/master
```
Damit Sie nicht aus versehen in das falsche Repository pushen müssen Sie git mitteilen, dass Sie ab jetzt in Ihren fork pushen wollen:

```
git push -u origin solution-003
```

Nun haben Sie den branch `main` aus meinem Repository in Ihren Fork übertragen.

# Aufgabenstellung

Implementieren Sie die fehlenden Code Teile

```cpp
// insert your code here....
```

## Nach getaner Arbeit

Haben Sie alle Punkte erfolgreich abgearbeitet erstellen Sie einen Pull-Request in Ihrem Fork und fügen mich ``graugans`` als Approval hinzu.

# Lernziele

- Vertiefung der git Kenntnisse
- Umgang mit Verkettenlisten
- Umgang mit der ``{fmt}`` Bibliothek