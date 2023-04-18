Biblioteka Action Editor (edytor akcji).
Ten przykład pokazuje, dlaczego NIE należy stosować QStandardItemModel,
a zamiast tego rozszerzyć abstrakcyjny model tablicowy.
Problem polega na tym: gdy modyfikujesz skrót, nie zobaczysz w tabeli 
zaktualizowanej wartości bez wprowadzania pewnego rodzaju notyfikacji o zdarzeniach.
Nie chcemy składować duplikatów danych w naszych standardowych elementach.
Z tego powodu, lepszym podejściem będzie rozszerzenie AbstractTableModel,
jak pokazuje przykład "shortcutmodel".
