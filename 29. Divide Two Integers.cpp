class Solution {
public:
    int divide(int a, int b) {

		 long int dividend = a;
		 long int divisor  = b;

		 if(dividend == INT_MIN && divisor == -1){return INT_MAX;} 
		 if(dividend == INT_MIN && divisor == 1){return INT_MIN;} 


		 int div = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
		 dividend = abs(dividend);
		 divisor = abs(divisor);
		 long int quot = 0;
		 while(dividend >= divisor){
			 int i = 0;
			 for(; i < 32 ; i++){
				 if( (long int)( (divisor) << i) > dividend){
					 break;
				 }
			 }    
			dividend -= (divisor << (i - 1));
			quot += (1 << (i - 1)); 
		 }
		 return (div) ? -quot : quot;
    }
};