
  while (n1 && n2){
    if (n1 && n2){
      if (n1->data>n2->data){
        printf("False\n");
        break;
      }else if (n1->data<n2->data){
        printf("True\n");
        break;
      }else{
        n1 = n1->next;
        n2 = n2->next;
      }
    }
    else if (n1&&!n2&&n1->data!=0){  
      printf("False\n");
      break;
    }
    else if (n2&&!n1&&n2->data!=0){  
      printf("True\n");
      break;
      }
    }
}
