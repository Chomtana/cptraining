/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		String sa = sc.next();
		String sb = sc.next();
		/**
		 * sc.nextLine();
		 * sc.nextInt();
		 * sc.nextFloat();
		 * sc.nextDouble();
		 * sc.nextLong();
		 */
		 
		BigInteger a = new BigInteger(sa);
		BigInteger b = new BigInteger(sb);
		BigDecimal da = new BigDecimal(sa);
		BigDecimal db = new BigDecimal(sb);
		
		// c = (a+b+1)*3
		BigInteger c = a.add(b).add(BigInteger.ONE).multiply(BigInteger.valueOf(3));
		
		// d = ab + 9
		BigInteger d = a.multiply(b).add(BigInteger.valueOf(9));
		
		// e = |a-b|
		BigInteger e = a.subtract(b).abs();
		
		System.out.println(c);
		System.out.println(d);
		System.out.println(e);
		
		if (a.compareTo(b) < 0) {
			System.out.println("a < b");
		} else if (a.equals(b)) {
			System.out.println("a == b");	
		} else {
			System.out.println("a > b");	
		}
		
		// dc = (da / db) * 3.5
		BigDecimal dc = da.divide(db).multiply(BigDecimal.valueOf(3.5));
		
		// dd = da mod db
		BigDecimal dd = da.remainder(db);
		
		System.out.println(dc);
		System.out.println(dd);
		System.out.println(dc.setScale(2, RoundingMode.HALF_UP));
	}
}