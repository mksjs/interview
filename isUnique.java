import java.util.*;

class isUnique{
	static boolean isUniqueChars(String str){
		if(str.length() >128) return false;
		boolean[] char_set = new boolean[128];
		for(int i=0;i<str.length();i++){
			int val =str.charAt(i);
			if(char_set[val])
				return false;
			else		
				char_set[val] = true;
		}
		return true;
	}
	public static void main(String [] args){
		Scanner sc =new Scanner(System.in);
		String s = sc.next();
		if(isUniqueChars(s)){
			System.out.println("Unique character in the String\n");
		}
		else{
			System.out.println("Not Unique character in the String\n");
		}
	}
}
