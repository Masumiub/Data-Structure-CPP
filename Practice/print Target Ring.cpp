void printTargetRing(AssassinNode* front) {
	AssassinNode* curr = front;
    int count=0;
    /*while(curr!=nullptr){
            count++;
            curr = curr->next;
    }

    if(count==1){
        cout<< curr->data << " is the winner!"<< endl;
    }*/


    while(curr!=nullptr){
        cout<< curr->data<< " is pursuing "<<curr->next->data<< endl;
        curr = curr->next;
    }



}
