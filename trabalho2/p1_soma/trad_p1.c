//++++++++++++++Soma +++++++++++++
List* soma(List* N1, List* N2){
  List* Nf = criar_lista();

  N1 = inverter_lista(N1);
  N2 = inverter_lista(N2);

  Node* n1 = N1->inicio;
  Node* n2 = N2->inicio;

  int extra = 0;

  while (n1 || n2){

    if (n1 && n2){
      int final = n1->data + n2->data + extra;
      int digito = 0;
      if (final >= 10){
        digito = final % 10;
        extra = 1;
      }else{
        digito = final;
        extra = 0;
      }
      add_no(Nf, digit);
      n1 = n1->prox;
      n2 = n2->prox;
    
    } else if (n1){
      int final = n1->data + extra;
      extra = 0;
      add_no(Nf, final);
      n1 = n1->prox;
    
    } else if (n2){
      int final = n2->data + extra;
      extra = 0;
      add_no(Nf, final);
      n2 = n2->prox;
      }
    }

    if (!N1->inicio->prox && !N1->inicio->prox)
      add_no(Nf, extra);

  return Nf;
}

