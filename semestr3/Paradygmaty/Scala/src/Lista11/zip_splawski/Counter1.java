package Lista11.zip_splawski;

public class Counter1 extends Thread
{
    protected int count, inc, delay;

    public Counter1( int  init,  int  inc,  int  delay )     
    {   this.count = init;
        this.inc = inc;
        this.delay = delay;
    }
    
    @Override public void run() 
    { try 
      { for (int i=0; i<30; i++) 
	    { System.out.print(count + " ");
          count += inc;
          sleep(delay);
        }  
      } catch (InterruptedException e) {}
    }

    public static void main(String[] args) 
    {   new Counter1(0, 1, 33).start();
        new Counter1(0, -1, 100).start();
    }
}