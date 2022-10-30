class amazon extends Thread
{

static int available=1;

synchronized public  void run()
{

if(available>0)
{
available--;
System.out.println(Thread.currentThread().getName()+" Booked  ");

}
else
{

 System.out.println(Thread.currentThread().getName()+" "+"out of stock");

}



}

public static void main(String args[])
{

amazon t1= new amazon();
amazon t2= new amazon();
amazon t3= new amazon();
amazon t4= new amazon();

t1.start();
t2.start();
t3.start();
t4.start();

}

}