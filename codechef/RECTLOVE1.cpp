#include <bits/stdc++.h>

using namespace std;

// Max length of BigInteger in base=1000000000

#define MAX_LEN 109
#define _max(a,b) (((a)>(b))?(a):(b))

const int base = 1000*1000*1000;

struct BigInteger{
    int d[MAX_LEN], len;
    //char sgn;
    BigInteger(long long val){
        len = 0;
        memset(d,0,MAX_LEN*sizeof(int));
        while(val>0){
            d[len]=val%base;
            val/=base;
            len++;
        }
    }
    BigInteger(){
        BigInteger(0ll);
    }
    BigInteger(const BigInteger & b){
        //sgn = b.sgn;
        len = b.len;
		for(int i=0;i<b.len;i++)
			d[i]=b.d[i];
    }
    static BigInteger fromStr(char *s, BigInteger& r){
        r.len = 0; //b.sgn = 1;
        for (int i=(int)strlen(s);i>0;i-=9){
            s[i] = 0;
            r.d[r.len++]=atoi(i>=9 ? s+i-9 : s);
        }
        while(r.d[r.len-1]==0) r.d[--(r.len)]=0;
        return r;
    }

    //Add BigInteger value to this
    BigInteger add(BigInteger &b){
        BigInteger r(b);
        int carry = 0;
        for (int i=0; i<_max(r.len,len) || carry; i++) {
            if (i == r.len)
                r.d[r.len++]=0;
            r.d[i] += carry + (i < len ? d[i] : 0);
            carry = r.d[i] >= base;
            if (carry)  r.d[i] -= base;
        }
        return r;
    }
    //Add __int64 value to this
    BigInteger add(long long b){
        BigInteger t(b);
        return add(t);
    }
    // Subtract BigInteger value from this (2.0)
    BigInteger subtract(const BigInteger &b, int sh=0){
        BigInteger r(*this), c(b);
		if(sh>0){
			for(int i=c.len-1;i>=0;i--)
				c.d[i+sh]=c.d[i];
			for(int i=0;i<sh;i++) c.d[i]=0;
			c.len+=sh;
		}
        int carry = 0;
        for(int i=0;i<c.len || carry; i++){
            r.d[i] -= carry + (i<c.len ? c.d[i] : 0);
            carry = r.d[i] < 0;
            if (carry) r.d[i] += base;
        }
        while(r.len > 0 && r.d[r.len-1] == 0)
            r.d[--(r.len)] = 0;
        return r;
    }
    //Multiply this by short integer (less than base)
    BigInteger multiply(int val){
        BigInteger r(*this);
        int carry = 0;
        for(int i=0;i<r.len || carry;i++){
            if(i==r.len)
                r.d[r.len++] = 0;
            long long cur = carry + (long long)(r.d[i])*val;
            r.d[i] = int(cur%base);
            carry = int (cur/base);
        }
        while(r.len>0 && r.d[r.len-1] == 0)
            r.d[--(r.len)] = 0;
        return r;
    }
    //Multiply this by BigInteger value
    BigInteger multiply(BigInteger &b){
        BigInteger r(0);
        r.len = len + b.len;
        for(int i=0;i<len;i++)
            for(int j=0, carry=0; j<b.len || carry; j++){
                long long cur = r.d[i+j] + (long long)d[i]*(j<b.len ? b.d[j] : 0) + carry;
                r.d[i+j] = int(cur%base);
                carry = int(cur/base);
            }
        while(r.len>0 && r.d[r.len-1] == 0)
            r.d[--(r.len)] = 0;
        return r;
    }

    //Divide this by short integer (less than base)
    BigInteger divide(int val, int &rem){
        BigInteger r(*this);
        rem = 0;
        for(int i = r.len-1; i>=0; i--){
            long long cur = r.d[i] + (long long)rem*base;
            r.d[i]=int(cur/val);
            rem=int(cur%val);
        }
        while(r.len>0 && r.d[r.len-1] == 0)
            r.d[--(r.len)] = 0;
        return r;
    }
	
	int findBin(BigInteger &rem,BigInteger &b, int sp){
		int down=0, up=base;
		BigInteger c;
		while(up-1>down){
			c=b.multiply((up+down)/2);
			int cm = abscmp(rem, c, sp);
			if(cm==1) down = (down+up)/2;
			if(cm==-1) up = (down+up)/2;
			if(cm==0){
				up = (down+up)/2;
				down = up;
			}
		}
		c=b.multiply((up+down)/2);
		if(abscmp(rem, c, 0)>0) rem=rem.subtract(c,sp);
		else{
			c = c.subtract(rem, sp); 
			rem=c;
		}
		return (up+down)/2;
	}
	//Divide this by BigInteger (2.0) [Okulov's algo]
	BigInteger divide(BigInteger &d, BigInteger &rem){
		rem = 0;
		BigInteger res = 0;
		int c = abscmp(d);
		if(c==0){
			res.d[0]=1; res.len=1;
			return res;
		}
		if(c<0){
			rem=*this;
			return res;
		}
		rem = *this;
		int sp = len-d.len;
		if(abscmp(*this, d, sp)<0) sp--;
		res.len=sp+1;
		while(sp>=0){
			res.d[sp]=findBin(rem, d, sp);
			sp--;
		}
		return res;
	}

    //Compare absolute values (this and other) (1.1)
    int abscmp(const BigInteger &other, int sh=0){
        if(len>other.len+sh) return 1;
        if(len<other.len+sh) return -1;
        for(int i=other.len-1;i>=0;i--)
            if(d[i+sh]>other.d[i]) return 1;
            else if(d[i+sh]<other.d[i]) return -1;
		for(int i=0;i<sh;i++)
			if(d[i]>0) return 1;
        return 0;
    }
	//Compare absolute values (a and b) (1.1)
	int abscmp(const BigInteger &a, const BigInteger &b, int sh=0){
        if(a.len>b.len+sh) return 1;
        if(a.len<b.len+sh) return -1;
        for(int i=b.len-1;i>=0;i--)
            if(a.d[i+sh]>b.d[i]) return 1;
            else if(a.d[i+sh]<b.d[i]) return -1;
		for(int i=0;i<sh;i++)
			if(a.d[i]>0) return 1;
        return 0;
    }

    //Power this (uses binary algo) (1.2)
    BigInteger pow(int val){
        BigInteger r = 1, a = *this;
        while (val>0)
            if ((val&1)==0){
                a = a.multiply(a);
                val >>= 1;
            }else{
                r = r.multiply(a);
                --val;
            }
        return r;
    }

    //Compare values
    //Since version 2.0
    int cmp(BigInteger &other){
        return 0;
    }

    //Square Root of this (1.5)
    BigInteger sqrt(){
        BigInteger r = 0;
        r.len = (len+1)/2;
        int cur = r.len-1;
        while(cur>=0){
            int up = base-1, down =0, v, c=0; 
            while(up>down){
                v=(up+down)>>1;
                r.d[cur]=v;
                c = r.multiply(r).abscmp(*this);
                if(c>0) up=v-1;
                else if(c<0) down=v+1;
                else break;
            }
            while(c<0){
                r.d[cur]++;
                c=r.multiply(r).abscmp(*this);
            }
            while(c>0){
                r.d[cur]--;
                if(r.multiply(r).abscmp(*this)<=0){
                    break;
                }
            }
            cur--;
        }
        return r;
    }

    //Greatest Common Divisor
    //Since version 2.0
    BigInteger gcd(BigInteger &other){
		BigInteger a(*this), b(other), tmp;
		while(b.len!=0){
			a.divide(b,tmp);
			a = b;
			b = tmp;
		}
		return a;
    }
};

// Overloaded operator '+'
BigInteger operator +(BigInteger &a, BigInteger &b){
    BigInteger r = a.add(b);
    return r;
}
// Overloaded operator '-'
BigInteger operator -(BigInteger &a, BigInteger &b){
    BigInteger r = a.subtract(b);
    return r;
}
// Overloaded operator '*'
BigInteger operator *(BigInteger &a, BigInteger &b){
    BigInteger r = a.multiply(b);
    return r;
}
// Overloaded operator '/'
BigInteger operator /(BigInteger &a, int b){
    int rem = 0;
    BigInteger r = a.divide(b, rem);
    return r;
}
// Overloaded operator '/'
BigInteger operator /(BigInteger &a, BigInteger &b){
    BigInteger rem = 0;
    BigInteger r = a.divide(b, rem);
    return r;
}
// Overloaded operator '%'
int operator %(BigInteger &a, int b){
    int rem = 0;
    if(b>=base) return a.d[a.len-1];
    else a.divide(b, rem);
    return rem;
}
// Overloaded operator '%'
BigInteger operator %(BigInteger &a, BigInteger &b){
    BigInteger rem = 0;
    a.divide(b, rem);
    return rem;
}
// Overloaded operator '^' (power) (1.3)
BigInteger operator ^(BigInteger &a, int b){
    BigInteger r = a.pow(b);
    return r;
}

//Overloaded operator << (for output)
basic_ostream<char>& operator<<(basic_ostream<char>& out, const BigInteger &b){
    short digs[9];
    if(b.len==0) out<<0;
    else{
        for(int i=b.len-1;i>=0;i--){
            int t=b.d[i], k = 0;
            for(int j=8;j>=0;j--){
                digs[j]=t%10;
                t/=10;
                if(t==0&&k==0) k=j;
            }
            if(i!=b.len-1) k = 0; 
            for(int j=k;j<9;j++) out<<digs[j];
        }
    }
    return out;
}
//Overload operator >> (for input)
basic_istream<char>& operator>>(basic_istream<char>& in, BigInteger &b){
    char s[MAX_LEN*9+1];
    in>>s;
    BigInteger::fromStr(s, b);
    return in;    
} 
//----- BigInteger ENDS -----

bool check(BigInteger &a, int p){
    BigInteger tmp(a);
    int rem;
    while(p>0){
        tmp = tmp.divide(2, rem);
        if(rem) return false;
        p--;
    }
    return true;
}


int main(){
    int t,K;
    cin>>t;
    long long int n,m,ele;
    while(t--){

        cin>>n>>m>>K;

        BigInteger a(n),b(m);
        BigInteger c=a*b*(a+1)*(b+1);
        c=c/4;
    }
	return 0;
} 