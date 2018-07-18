import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int numero;
			ArrayList<Integer> numeros = new ArrayList<Integer>();
			while(sc.hasNext()){
				numero = sc.nextInt();
				if(numero == -999999) break;
				numeros.add(numero);
			}
			BigInteger localMax = BigInteger.valueOf(numeros.get(0));
			BigInteger localMin = BigInteger.valueOf(numeros.get(0));
			BigInteger maxProd = BigInteger.valueOf(numeros.get(0));
			for(int i = 1; i < numeros.size(); i++){
				if(numeros.get(i) > 0){
					BigInteger tmp = localMax.multiply(BigInteger.valueOf(numeros.get(i)));
					localMax = tmp.max(BigInteger.valueOf(numeros.get(i)));
					BigInteger tmp2 = localMin.multiply(BigInteger.valueOf(numeros.get(i)));
                                        localMin = tmp2.min(BigInteger.valueOf(numeros.get(i)));
				}else{
					BigInteger tmp = localMin.multiply(BigInteger.valueOf(numeros.get(i)));
                                        BigInteger localMaxNeg = tmp.max(BigInteger.valueOf(numeros.get(i)));
					BigInteger tmp2 = localMax.multiply(BigInteger.valueOf(numeros.get(i)));
					localMin = tmp2.min(BigInteger.valueOf(numeros.get(i)));
					localMax = localMaxNeg;
				}
				maxProd = maxProd.max(localMax);
			}
			System.out.println(maxProd);
		}
	}
}
