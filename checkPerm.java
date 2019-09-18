import java.util.*;

class checkPerm{
	static String sort(String str){
		char[] content = str.toCharArray();
		Arrays.sort(content);
		return new String(content);
	}
	static boolean permutation(String s, String t){
		if(s.length() != t.length())
			return false;
		return sort(s).equals(sort(t));
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		if(permutation(s,t)){
			System.out.println("one String is permutaion of other");
		}
		else{
			System.out.println("not permutation of each other");
		}
		
	}
}
