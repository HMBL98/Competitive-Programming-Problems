import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		BigInteger numero,i,tmp;
		String res;
		while(sc.hasNext()){
			numero = sc.nextBigInteger(); tmp = numero; res = "";
			if(numero.compareTo(new BigInteger("-1")) == 0)break;
			if(numero.compareTo(new BigInteger("0")) == 0)System.out.println("10");
			else{
				for(int j = 9; j > 1; j--){
					i = BigInteger.valueOf(j);
					while(numero.mod(i).compareTo(BigInteger.ZERO) == 0){
						res += i;
						numero = numero.divide(i);
					}
				}
				if(numero.min(new BigInteger("10")) != numero){
					System.out.println("There is no such number.");
				}else{
					if(tmp.min(new BigInteger("10")) == tmp){
						System.out.println("1"+tmp);
					}else{
						for(int k = res.length()-1; k >= 0; k--){
							System.out.printf("%c",res.charAt(k));
						}
						System.out.printf("\n");
					}
				}
			}

		}
	}
}
