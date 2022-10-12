import java.util.Scanner;

public class Main
{
	public static int[] toBinary(int decimal){    
     int binary[] = new int[40];    
     int index = 0;    
     while(decimal > 0){    
       binary[index++] = decimal%2;    
       decimal = decimal/2;    
     }    
     for(int i = index-1;i >= 0;i--){    
       System.out.print(binary[i]);    
     }    
    System.out.println();
    return binary;
    } 
     
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int[][] S0 = { { 1, 0, 3, 2 },
                   { 3, 2, 1, 0 },
                   { 0, 2, 1, 3 },
                   { 3, 1, 3, 2 } };
        
        System.out.println("S0 Matrix");
        
        for ( int i =0;i<4;i++) {
            for ( int j =0;j<4;j++) {
                System.out.print(S0[i][j]);
            }
             System.out.println("");
        }
        
        System.out.println("Enter decimal between 0 to 15 :");
        int num = sc.nextInt();
        
        int[] n = toBinary(num);
        
        int row = Integer.parseInt("" + n[0] + n[3], 2);
        int col = Integer.parseInt("" + n[1] + n[2], 2);
        int val = S0[row][col];
        System.out.println("Output :"+val);
    }
}
