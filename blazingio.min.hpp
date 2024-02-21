// DO NOT REMOVE THIS MESSAGE. The mess that follows is a minified build of
// https://github.com/purplesyringa/blazingio. Refer to the repository for
// a human-readable version and documentation.
// Options: cbfoiedrhWLMXaIaAn
#define L$(x)_mm256_loadu_si256(x)
#define M$(x,...)_mm256_##x##_epi8(__VA_ARGS__)
#define $u(...)__VA_ARGS__
#if __APPLE__
#define $m(A,B)A
#else
#define $m(A,B)B
#endif
#if _WIN32
#define $w(A,B)A
#else
#define $w(A,B)B
#endif
#if __x86_64__|_M_X64
#define $H(A,B)A
#else
#define $H(A,B)B
#endif
#if __x86_64__|__i386__|_M_X64|_M_I386
#define $S(A,B)A
#else
#define $S(A,B)B
#endif
#define $T template<
#define $c class
#define $C constexpr
#define $R return
#define $O operator
#define $r $R*this;
#include<array>
#include<bitset>
#include<complex>
#include<cstring>
#include $S(<immintrin.h>,<arm_neon.h>)
#include<stdint.h>
#include $w(<windows.h>,<sys/mman.h>)
#include<sys/stat.h>
#include $w(<io.h>,<unistd.h>)
#ifdef _MSC_VER
#define $s
#else
#define $s $S(__attribute__((target("avx2"))),)
#endif
#define $z $S(32,16)
#define $t $S(__m256i,uint8x16_t)
#define $I $w(__forceinline,__attribute__((always_inline)))
#define $F M(),
#define E$(x)if(!(x))abort();
$w(LONG WINAPI $x(_EXCEPTION_POINTERS*);,)namespace $f{using namespace std;struct B{enum $c A:char{};A c;B&$O=(char x){c=A{x};$r}$O char(){$R(char)c;}};const uint64_t C=~0ULL/255;struct D{string&K;};static B E[65568];$T bool F>struct G{B*H;B*I;void K(off_t C){$w(char*D=(char*)VirtualAlloc(0,(C+8191)&-4096,8192,1);E$(D)E$(VirtualFree(D,0,32768))DWORD A=(C+4095)&-65536;if(A)E$(MapViewOfFileEx(CreateFileMapping(GetStdHandle(-10),0,2,0,A,0),4,0,0,0,D)==D)E$(VirtualAlloc(D+A,65536,12288,4)==D+A)E$(~_lseek(0,A,0))DWORD E=0;ReadFile(GetStdHandle(-10),D+A,65536,&E,0);,char*D=(char*)mmap(0,C+4096,3,2,0,0);E$(D!=(void*)-1)E$(mmap(D+((C+4095)&-4096),4096,3,$m(4114,50),-1,0)!=(void*)-1))H=(B*)D+C;*H=10;H[1]=48;I=(B*)D;}void L(){H=I=E;}$I void M(){if(F&&I==H){$w(DWORD A=0;ReadFile(GetStdHandle(-10),I=E,65536,&A,0);,$S(off_t A=$m($S(33554435,3),$S(0,63));B*D=E;asm volatile($H("syscall","int $128"):"+a"(A),$H("+S"(D):"D","+c"(D):"b")(0),"d"(65536)$H($u(:"rcx","r11"),));I=D;,$u(register long A asm("x0")=0,D asm("x1")=(long)E,G asm("x2")=65536,C asm($m("x16","x8"))=$m($S(33554435,3),$S(0,63));asm volatile("svc 0"$m("x80",):"+r"(A),"+r"(D):"r"(C),"r"(G));I=(B*)D;)))H=I+A;*H=10;if(!A)E[1]=48,H=0;}}$T $c T>$I void N(T&x){while($F(*I&240)==48)x=x*10+(*I++-48);}$T $c T>$I enable_if_t<is_integral_v<T>>O(T&x){bool A=is_signed_v<T>&&($F*I==45);I+=A;N(x=0);x=A?1+~x:x;}$T $c T>$I decltype((void)T{1.})O(T&x){bool A=($F*I==45);I+=A;$F I+=*I==43;uint64_t n=0;int i=0;for(;i<18&&($F*I&240)==48;i++)n=n*10+*I++-48;int B=20;bool C=*I==46;I+=C;for(;i<18&&($F*I&240)==48;i++)n=n*10+*I++-48,B-=C;x=(T)n;while(($F*I&240)==48)x=x*10+*I++-48,B-=C;if(*I==46)I++,C=1;while(($F*I&240)==48)x=x*10+*I++-48,B-=C;int D;if((*I|32)==101)I++,$F I+=*I==43,O(D),B+=D;static $C auto E=[](){array<T,41>E{};T x=1;for(int i=21;i--;)E[40-i]=x,E[i]=1/x,x*=10;$R E;}();if(0<=B&&B<41)x*=E[B];else{while(B-->20)x*=10;while(++B<20)x*=.1;}x=A?-x:x;}$I void O(bool&x){$F x=*I++==49;}$I void O(char&x){$F x=*I++;}$I void O(uint8_t&x){$F x=*I++;}$I void O(int8_t&x){$F x=*I++;}$T $c T>$s void P(string&K,T C){M();auto G=I;C();K.assign((const char*)G,I-G);while(F&&I==H){if($F!H){H=I;break;}C();K.append(E,I);}}$s void O(string&K){P(K,[&]()$s{$t*p=($t*)I;$w(ULONG index;,)$S($u(int mask;__m256i C=M$(set1,32);while(!(mask=M$(movemask,M$(cmpeq,C,_mm256_max_epu8(C,L$(p))))))p++;I=(B*)p+$w((_BitScanForward(&index,mask),index),__builtin_ctz(mask));),$u(uint64x2_t A;while(A=(uint64x2_t)(*p<=32),!(A[0]|A[1]))p++;I=(B*)p+(A[0]?0:8)+$w((_BitScanForward64(&index,A[0]?:A[1]),index),__builtin_ctzll(A[0]?:A[1]))/8;))});}$s void
O(D&A){P(A.K,[&](){I=(B*)memchr(I,10,H-I+1);});if(A.K.size()&&A.K.back()==13)A.K.pop_back();if(A.K.empty()||I<H)I+=*I==10;}$T $c T>$I void O(complex<T>&K){T A,B{};if($F*I==40){I++;O(A);if($F*I++==44)Q(B),I++;}else O(A);K={A,B};}$T size_t N>$s void O(bitset<N>&K){if(N>=4096&&!*this)$R;ptrdiff_t i=N;while(i)if($F i%$z||H-I<$z)K[--i]=*I++==49;else{auto p=($t*)I;for(int64_t j=0;j<min(i,H-I)/$z;j++){i-=$z;$S(uint64_t a=~0ULL/65025;((uint32_t*)&K)[i/32]=$w(_byteswap_ulong,__builtin_bswap32)(M$(movemask,M$(shuffle,_mm256_slli_epi32(L$(p++),7),_mm256_set_epi64x(a+C*24,a+C*16,a+C*8,a))));,$u(auto B=(uint8x16_t)vdupq_n_u64(~2ULL/254)&(48-*p++);auto C=vzip_u8(vget_high_u8(B),vget_low_u8(B));((uint16_t*)&K)[i/16]=vaddvq_u16((uint16x8_t)vcombine_u8(C.val[0],C.val[1]));))}I=(B*)p;}}$T $c T>$I void Q(T&K){if(!is_same_v<T,D>)while($F 0<=*I&&*I<=32)I++;O(K);}$O bool(){$R!!*this;}bool $O!(){$R I>H;}};struct $i{G<0>A;G<1>B;$i(){struct stat D;E$(~fstat(0,&D))(D.st_mode>>12)==8?A.K(D.st_size):B.L();}void*tie(nullptr_t){$R 0;}$T $c T>$I $i&$O>>(T&K){A.I?A.Q(K):B.Q(K);$r}$O bool(){$R!!*this;}bool $O!(){$R A.I?!A:!B;}};char decimal_lut[200];struct $o{char*D;B*I;$o(){$w(E$(D=(char*)VirtualAlloc(0,536870912,8192,4))E$(VirtualAlloc(D,4096,4096,260))AddVectoredExceptionHandler(1,$x);,D=(char*)mmap(0,536870912,3,$m(4162,16418),-1,0);E$(D!=(void*)-1))I=(B*)D;for(int i=0;i<100;i++)decimal_lut[i*2]=char(48+i/10),decimal_lut[i*2+1]=char(48+i%10);}~$o(){flush(1);}void flush(int F=0){$w(auto E=GetStdHandle(-11);auto C=F?ReOpenFile(E,1073741824,7,2684354560):(void*)-1;DWORD A;E$(C==(void*)-1?WriteFile(E,D,DWORD((char*)I-D),&A,0):(WriteFile(C,D,DWORD(((char*)I-D+4095)&-4096),&A,0)&&~_chsize(1,int((char*)I-D)))),auto G=D;ssize_t A;while((A=write(1,G,(char*)I-G))>0)G+=A;E$(~A))I=(B*)D;}void F(char K){*I++=K;}void F(uint8_t K){*I++=K;}void F(int8_t K){*I++=K;}void F(bool K){*I++=48+K;}$T $c T,int Digits,T D=1>void G(T K,T E,B*&p){if $C(Digits==1){*p++=48+E;}else if $C(Digits==2){*p++=decimal_lut[E*2];*p++=decimal_lut[E*2+1];}else{$C auto A=[](){int F=1;T H=10;while((F*=2)<Digits)H*=H;$R pair{F/2,H};}();$C int F=A.first;$C T H=A.second;G<T,Digits-F,T(D*H)>(K,E/H,p);G<T,F,D>(K,E%H,p);}}$T $c T>enable_if_t<is_integral_v<T>>F(T K){if(K==0){F('0');$R;}using AbsT=make_unsigned_t<T>;AbsT A=K;if(K<0)F('-'),A=1+~A;if $C(sizeof(T)==1){int digits=(A>=10)+(A>=100);B buf[3+3];memcpy(buf,decimal_lut+A/10*2,2);buf[2]=48+A%10;memcpy(I,buf+3-digits,4);I+=digits;$R;}static $C char max_digits_by_log2[]={1,1,1,2,2,2,3,3,3,4,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,10,10,10,10,11,11,11,12,12,12,13,13,13,13,14,14,14,15,15,15,16,16,16,16,17,17,17,18,18,18,19,19,19,19,20};static $C auto powers_of_ten=[](){array<AbsT,sizeof(T)==2?5:10>powers_of_ten{};AbsT n=1;for(int i=1;i<powers_of_ten.size();i++){n*=10;powers_of_ten[i]=n;}$R powers_of_ten;}();int digits=max_digits_by_log2[31-__builtin_clz(A)];digits-=A<powers_of_ten[digits-1];if $C(sizeof(T)==2){uint32_t n=33555*A-A/2;uint64_t buf=((uint16_t*)decimal_lut)[n>>25];n=(n&33554431)*25;buf|=((uint16_t*)decimal_lut)[n>>23]<<16;n=(n&8388607)*5;buf|=(uint64_t)(48+(n>>22))<<32;*(uint64_t*)I=buf;I+=digits;$R;}if $C(sizeof(T)==4){uint64_t n=1441151881ULL*A;uint16_t buf[5+8];int shift=57;uint64_t mask=0x1ffffffffffffff;
#pragma GCC unroll 5
for(int i=0;i<5;i++){buf[i]=((uint16_t*)decimal_lut)[n>>shift];n=(n&mask)*25;shift-=2;mask>>=2;}memcpy(I,(B*)buf+10-digits,16);I+=digits;$R;}char buf[20+32];char*p=buf+20;while(A>=100){T lower=A%100;*--p=decimal_lut[lower*2+1];*--p=decimal_lut[lower*2];A/=100;}*--p=decimal_lut[A*2+1];if(A>=10){*--p=decimal_lut[A*2];}memcpy(I,p,32);I+=buf+20-p;}$T $c T>decltype((void)T{1.})F(T K){if(K<0)F('-'),K=-K;auto A=[&](){auto x=uint64_t(K*1e12);G<uint64_t,12>(x,x,I);};if(!K)$R F('0');if(K>=1e16){K*=1e-16;int B=16;while(K>=1)K*=.1,B++;F("0.");A();F('e');F(B);}else if(K>=1){auto B=(uint64_t)K;F(B);if(K-=B)F('.'),A();}else F("0."),A();}void F(const char*K){$w(size_t A=strlen(K);memcpy((char*)I,K,A);I+=A;,I=(B*)stpcpy((char*)I,K);)}void F(const uint8_t*K){F((char*)K);}void F(const int8_t*K){F((char*)K);}void F(string_view K){memcpy(I,K.data(),K.size());I+=K.size();}$T $c T>void F(complex<T>K){*this<<'('<<K.real()<<','<<K.imag()<<')';}$T size_t N>$s void F(const bitset<N>&K){auto i=N;while(i%$z)*I++=48+K[--i];auto p=($t*)I;i/=$z;while(i){$S(auto b=_mm256_set1_epi64x(~2ULL/254);_mm256_storeu_si256(p++,M$(sub,M$(set1,48),M$(cmpeq,_mm256_and_si256(M$(shuffle,_mm256_set1_epi32(((uint32_t*)&K)[--i]),_mm256_set_epi64x(0,C,C*2,C*3)),b),b)));,auto A=(uint8x8_t)vdup_n_u16(((uint16_t*)&K)[--i]);*p++=48-vtstq_u8(vcombine_u8(vuzp2_u8(A,A),vuzp1_u8(A,A)),(uint8x16_t)vdupq_n_u64(~2ULL/254));)}I=(B*)p;}$T $c T>$o&$O<<(const T&K){F(K);$r}$o&$O<<($o&(*A)($o&)){$R A(*this);}};struct $e{$T $c T>$e&$O<<(const T&K){$r}$e&$O<<($e&(*A)($e&)){$R A(*this);}};}namespace std{$f::$i i$;$f::$o o$;$f::$e e$;$f::$i&getline($f::$i&B,string&K){$f::D A{K};$R B>>A;}$f::$o&flush($f::$o&B){if(!i$.A.I)B.flush();$R B;}$f::$o&endl($f::$o&B){$R B<<'\n'<<flush;}$f::$e&endl($f::$e&B){$R B;}$f::$e&flush($f::$e&B){$R B;}}$w(LONG WINAPI $x(_EXCEPTION_POINTERS*A){auto C=A->ExceptionRecord;char*B=(char*)C->ExceptionInformation[1];if(C->ExceptionCode==2147483649&&(size_t)(B-std::o$.D)<0x40000000){E$(VirtualAlloc(B,16777216,4096,4)&&VirtualAlloc(B+16777216,4096,4096,260))$R-1;}$R 0;},)
#define freopen(...)if(freopen(__VA_ARGS__)==stdin)std::i$=$f::$i{}
#define cin i$
#define cout o$
#ifdef ONLINE_JUDGE
#define cerr e$
#define clog e$
#endif
// End of blazingio
