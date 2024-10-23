import java.util.*;
class main{
    public static void main(String...args)
    {
        Scanner sc= new Scanner(System.in);
        String s=sc.next();
        String sub=sc.next();
        int f=0,f1=0,i,j;
        for(i=0;i<s.length();i++)
        {
            if(sub.charAt(0)==s.charAt(i))
            f=0;
            for(j=0;j<sub.length();j++)
            {
                if(sub.charAt(j)!=s.charAt(j+i))
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                System.out.println("match found");
                f1=1;
                break;
            }
        }
        if(f1==0)
        {
            System.out.println("not found");
        }
    }
}