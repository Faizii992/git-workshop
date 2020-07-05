=5;



int y;


int signal(int s)
{
    return (++s);}

int wait(int s)
{
    return (--s);
}

void producer(int mtex)
{
empt=wait(empt);
mtex=wait(mtex);
x++;
cout<<"Producer produces item: "<<x<<endl;

full=signal(full);
mtex=wait(mtex);


}

void consumer(int mtex)
{

full=wait(full);
mtex=wait(mtex);
cout<<"Consumer consumes item: "<<x<<endl;
x--;


empt=signal(empt);
mtex=signal(mtex);



}


int main()
{

int mtex=2;
full=2;
cout<<"Enter the number of resources: "<<endl;
cin>>n;
empt=n;
while(1)
{
cout<<"Enter 1 to produce,2 to consume,3 to exit "<<endl;
cin>>y;
    switch(y){
case 1:
    if(empt!=0&&mtex==1)
    {


    producer(mtex);
    }
    else{
        cout<<"Basket is full"<<endl;
    }
    break;
case 2:
     if(full!=0&&mtex==1)
    {


   consumer(mtex);
    }
    else{
        cout<<"Basket is empty"<<endl;
    }
    break;


case 3:

    exit(0);
    break;

    }
}



}
