#include "../include.h"

class Solution {
public:
	//之前用的值传递 vector<vector<char> > board, 一直报 LTE
    bool found(vector<vector<char> > &board, int i, int j, int M, int N, string word, int pos, int sLen) {
        if(pos == sLen - 1) {
            return board[i][j] == word[pos];
        }
        
        if(board[i][j] != word[pos]) {
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '*';
        
        bool res = false;
        if(!res && (i - 1) >= 0) {
            res = found(board, i - 1, j, M, N, word, pos + 1, sLen);
        }
        if(!res && (i + 1) < M) {
            res = found(board, i + 1, j,  M, N, word, pos + 1, sLen);
        }
        if(!res && (j - 1) >= 0) {
            res = found(board, i, j - 1,  M, N, word, pos + 1, sLen);
        }
        if(!res && (j - 1) < N) {
            res = found(board, i, j + 1,  M, N, word, pos + 1, sLen);
        }
        board[i][j] = c;
        return res;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int M, N, sLen;
        if(!(M = board.size())) {
            return false;
        }
        N = board[0].size();
        if(!(sLen = word.size())) {
            return false;
        }
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
				if(board[i][j] == word[0] && found(board, i, j, M, N, word, 0, sLen)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


vector<vector<char> > buildBoard(char b[][72], int r, int c) {
	vector<vector<char> > board;
	for(int i = 0; i < r; i++) {
		vector<char> v(b[i], b[i]+c);
		cout << b[i] << endl;
		board.push_back(v);
	}
	cout << "----------" << endl;    
	return board;
}

int main() {
	Solution s;
	
	char b1[97][72] = {"dgtjaljwlwsbdpqnjnlvrafrtmdrecekkxvliejwcdxfsosedfbxhgoastuzxylivgtgke","enibsarngxuhucpkckeyjbwwjucecojgdtjwtdlaafjwjzgojkmuojqzfughirnmkykfbx","hberxoqgcbsoxgznigjoprfefpdrweoegvvfjnlnqednmdcullkbepfkgidfnujvpgcyvo","lluoaitcffnpirhpdpyhunddkslmqgcdtytthpxmwkbeeitjatsuivasnlffujkpielpvi","drvexzpsirmbluwnpmburvfcmngxebghuborcfjkwvnjsmxhyydptirhyzfccnkwqansfz","edwsmqejxchcrcnlklkpppeblubbmicqlykypohosprmrgxbtjsiywkmslneupxfphfeyn","vqcocvuzznjtvjshvktkrpzowrvcvtrqktgoqaorpzllkdsgpnqgesubjsfglwzxrfojgc","bvdminrdvgqmnxejypbfvpduouacdieedjsozjrushghgmqgbslxhorvktyobeufontnym","hsvqzccqieiudrkwmvqmlrrfwhurwvdfnzxnbafjgnflgqhulxhwpadnjaffvkmklkxmme","yurdfzvmuimbgbdkomkvtfgfrrrpgftgznjgmhviphjwiogyasutzcbqvshdydjzsvggcb","priapspxqppmlqomhmgqpgtzgnuouwrjpblhtaelswydmmpvyxooehpmvjcrhtcyunfpom","agiylwncsnzgddpsrmbtdkmfjivqxjcarkycjlgdbflelcxcpayulkcwvxouirubdtfmgl","rhqcmdflgwleqyquuntjibccefxjuewlnnobqvmyraejyxevkxesbivfpurjanxocnrvie","vzeaiexozhofcpnxwdtpoudlkhabeihajlauszkrgyxinkhmpbbgxgrhouisequodukvvu","nctmmiywuozwuwendujlnodjejeoezktddfsmgoiwngqllfofrbuffejokzuljqppvjddz","lzmsrzdznkqqfvxjglvfigqyxfvgizfuytosstrhdhyicvtkjoptxfrulodvpipqefiyyz","icggmkdguowjhtqaodrtzgdqyhwgiwfqynylzbttqrezlxcbatuzbxsahogpkofldfydgt","wykdavacyavucysuybkfqwvxhyehdkacllflifphhmbjkvfjyrqqonpxntfrgftrqaezfv","iohlarjfchxsynfnktjpmpvhgnhmoohycokchvkkcjecwksgfbwtstaaihmxvvxzljcseo","ejxjntvfzcixvasxcbeoablxawhepnsvwpekkbrmdcjaeexhfdxhejehfnnwbgszxyjkad","wdfhelldsshqznbgugtkfusxupxfbxkxdphhdskvltnmhosdxmncifbexymywwyzmfirzu","mkocxvsrypdorotusqteprbpspuagtwugkwfhpwigcwaqpuigppxgsoahicpdzjjjiqtzp","bfrxhjoctwtitcahcjrfavekgpuzivolahkkqzmjvfurjuamgsrgpxsxmoyxjokmvvwluk","xrpriznlnvfecwdwvpluouizggwcrqmqjejsfxduukywgdvbsgvjagkjmgnfycwhifbneg","hzqhxwksyeavpdbzmnfbtfdrnlyoafvhenqdkcykjyfybjypwfrrlukaijqiqlswbizlnx","vwycublurkcidpeqrmbhxrvpnwzohmoeimifnwbgifqnwvdnjexgxsxkoxzxjndubnbqje","xtmnhikkywrveoncbdzcakrfesshieofxaveihridkdiasmbxldzvwecozlxdzeazbhkjy","umiywksimqvrptowxevidykiyjlfvufqjpqhakqoanfsgvodalodjynjjbrhvyxgopoozg","ectluchkhjvvogvephfioahnjvexlddpfwabajnisifhqblgkqoasvnbstadwduecvhcgv","mzfsiwtvednsfhqslillojpiptfxxosknxcxvxszchuhokbzuolixctpxamuoegddkabhu","albussgvrbjeljieyfhkcvqkzvvbwewzqztktagldrroaatahamjxeuyapaytyzlztwtvc","gytxowxhwfjjqjpkhrbhqxhpihkeahighefwaffykrjcazpjqqtipayajkgluprdvzzveh","tqadsachlsaebrfbrqnycjptnksohyvaovfhxhqjcqpfiuiblxzphqiwadkjdiksfpzdzp","odidksautnrvcalmworhxvpjnubozcfphntrfvlbkewmfhabxsixpzgcuhsvlxlsngjsbw","tnbrzibbjytuvkteoplglzeyrredlhzhucyvkbwwaqqxcjbrbpxmodkfwqiixkrrormbti","xtansdyuwzltnbxzgtprdmdwfroruhcrcegwjfsfgdbweyvntlgzxjvfclwxuaqyhxvqen","ymtzixzemurstqdrvieuhzuxxduuwaiunbvvawbpqshmlnfgxjaekxbiaycyamunpplsno","hejqsufzackdgvakfckjbkwvannlfcboikfaekbhpmkvhkhmorvretpejerogsdpdkphwt","qlfajmmqabkxuorjscnjqubvjghaqetgrahamvtoydmtrfclhswzmzxxgezwktecvleijx","whckavpdiyveyjevimbhkmcoqycwgluesyrvwiyehvjfgpcobdvlrybhydegqakjadewme","btbmajbcxehurzusgsymyomlznoflclmvmyxxbzufjrwinrqgpdgfrtfgkksmwekkfhigj","emsxkcldstsvbapvfvhrnvpufcbpmhyqvsqiudlmwgkzgbwnwdemzwigyjxmsxeopuwlxj","avpmvxnrkjxrxynfgnoezhbdxtavexeevwqstdlepixmimupzitarwfqphluhsacorujwf","nnqkaywupxeizyhhowocqxurzikvtibhwttyrsuhrartyycpvsrnqlgpvsnodoxzhtzanv","jgxbbwbdnyweomrudmpqcsgctpvsskpbqmeskgxxgtduhurnigdlymnrbkltuaxmobgbje","aqzemhadujjzwhljapvlkrnhdejmfuqfkrjzakcwvmwrvjcwaxjloxutbdfiaxnmpzlpjo","oeckvxvxvwwhjkedfhjlpjkcvzbhrmvfszrpymoukkbtwhxcqgpfrzjmbnvsbszurslqea","mrmnmjwjnmrctkdexerswtlxpepauwagnnvbytnlheparsfoxyivtvviaklwinfxcczawm","ndseejxlzwjktdfonhzygjmlhongrjsepmjvwigxerhxwnokwpkcywnfndleofkdutyqdg","nhavhwkxiimtlkraqeddkslvxfowxuembejkdthnetgpgaryexdrpomovcmswrfaxomaku","oopwfvwyvdvzumniblkndhgkjebvglpwbhvietiawezssoavznlfwrpfvqaedsagbxqfrz","hnfiizzkvyzgfvxvavndbtxdzybsfstnhavrzucuvbcazcxbzlgagddhbezhyuwgutzuob","qlftngxlhwyowetblvineghaoctoyjrowyjkegvoeveabxcoukdyslahpwxnfodeppotxl","jcgncjngxhsbinokudgtsohxuyoismtdobtsmibjrtmzgamcfuvzkfzednmxzhdpkwiwej","iveuxnxlrefnequfwzsjzuscjfatbeelbliayflpjrepjaufanqzjjdsodorjsdkdlldsw","vbpbtacniecyfljiezlurumwgsjrxbqsehuxkylscnqhzarfzezsynoghzafaszfzveltr","dxfwggyxnxbosbdiknikukctrdrwpmnsmuoscmspmvfgzjojwytqlxlcaeaprokdkaxnpp","edlklmvbvtaqjlnwpnbqfserxqrudikknxuyjragkawvnjrcyusdoyulroiwyugmtckctk","ifmgabpugnqytfzpssfcoewvspzcttpdydjbfyxlonljumyneervkoqcfpgzkvclbmoiml","tcaglvvmkbqbwcroexekwqiabjorrdcmfdutypfktxlpzdedakpyaxaeirvbuanbfiufzb","psyckzfochauharigczedverwlbtqcwhxvjjupxzyztgzmqiormumsnkfqfvsccrznatez","udyplacdiswwmkqzuvpcskewddjeyoftteiegmjohfmtpcvlzmnryrncuwitmnoftyjzls","nszbnofkaexpvvhkxdhfyvvmbonmoyhdsgfhxksxrrmmovxmzgtxbqmefzrtzywtedcbqw","ahnptcksqlallecxihyzczzaseeuhwridgzykltaxtokzsjkzhjdgldapjwyfpiiwhjivc","jsxzexrnhsusvcdaeukatrqdcollwgnhakigjztqrploropvlbxgupjwfwhcewlgjumsvf","lpuwdnmukzxkfszpoflyjswuyfqlamsldpjicxfpxczewatnfhnqzjlzpdkrrdeuundymi","njmoojpjywslntuatlfdcxigtcvydkiqvvhlgyveuppjjllcxrfboqkjuhixrqqnlzytxv","xtloduaqwzhdcxvohswprpfhetgdmfamznceheuffelibiwiauzukfboaktmpwaqjduthr","apvlxwwvhyqgscnwqnimczicqrhmkrdlgyyfxwagvsmpucnlpvztvhwnyfzlydyedwjcvm","iqexhzzvmqqlknsiaspafofdskcenxsxpwwyxvtlomwazqiclzcsnjwitaogxggoecmeai","pouoovgyxrzbknmivgijohruxvxlbxtrnpfdnldmfcqrpcbmijxxsotpmqanpwgennhazk","pgnfzehatsjqpdhkuvbwkssrxgeeifrxngcmmmmfexyvaffuairmbldatkgepxbdfgpsse","zybxtecaaejrrmfwmygucysgbzmstgwteaszevzebiyswdridxdivxqyyetskrnqrfpxcq","cebcyxhpimpnwkmmlkqeecxtspzjodcqhduiabzkqoxmblzmwpscupwmgxyvcanmfiuhlt","sbkrqldpzbgtdaibprapmdpbpwjldxevaqnqbshctqvwqgahxawlfnmujyfnvmkxezqgrz","kkpgjimlplnmwtziplgxydlidpitxbuimkoxscihnvvlqxtgicdihoqkfafdcalqmbpedx","nsujdliytqayykoqwtrcwvejnskcwnbjhvukicjdulbsvrjslcwjzctmudqqtrbaoylzaw","cvhgpdzavkctwdvrppuffpyisngfmjbqeiyvnywkkadgeyxvnudujbdbolgcujvastwhrs","sesvkwuishevcpyhrpszrnjondilkbdefwasuucmdgjhviooxjqqwbhlgrxsucxayxuttw","hwetebdsscbiuzlbnrsmlnoipphjkahtznmdopxgtbqocbppukdgzsqojyztyiozvbcjsc","smdicfmtxgdaocufsffrafzpfwqhgkjyyoiauwwtdzvtesayxfsylrnqofzwplwqzgsvdo","qiqmbwecubjmbwgoowvounbqdawvyzmojealaepwiajjxralnvbhiczndxldzxributdak","zilkukbuvorxxazwpewahvzbdavzfvjfgwpagrwehnbhpcffjbhqwhtajozpmkwuhlupes","tohwvzbagkcncauwagmbvymruveqmjiixsgsrhuxrykuzhsznedkfpbzmhqyqainsphjwe","iqcvmbeedrkgdpxgrlnjlejuteldpjhyzjvnnzrsscyvtxbkiotvufpqjctymcylntzass","skwshsrkebbyxvfonorgofknqygrabmvnknvchfhkghhemyrcryqwkfoioijpuecetzjaf","qnlxupjujnlhfjtlyczilqcruikurnzhamgweptnegwkqpvqtwygocxikkeezfnbuuzyls","nszlcrczhwxfenhcvtocznhpqblpbykqqjdscgtjeqqidxmbsafspmjfquxtshkjspduxx","fbpvmvuaymbdgsppyhlvbeenpweuscrxfjsrgoseavhjnyangmkjqoyfmczggtdmexfklz","oowvzkvzzblkmbamiprkvxfbljarvosjcpgbbdaafomtpniaezkzypakaddvrvgvkowlry","mymyuencerbqtzhvlhyoepkmkuciivjuwxuqbkuhdxxwyesknqytiifufjdnfojdlftppp","wtmwrkcjuscvlmftgmelbjzmmlshcjwyekwwvbhrtlogxuzgigrkprweeongamggwdctgm","nzxbfxxhdgnwqenmktdybfmilinqetcrububysidyxaqepcojhomoaualjqreuiyvccwwk","zukzkoppeayvmnxjpiufbzbjzyobumouhavtqmkumlpbypknzeubfvmfvaiqpymwyjrowe","lkpclnrvcrcwshteoohzgwxsuwcnmarxkgcwvttxkxvehqjvhsunquimqmzemreyzgwvzq","smpqqwgbspvoflinxabxfpqjnprkkqcfcrvvodwitsyydhndjoaqdsbshseslgxnauioxh","yqzwoefbhrrjhwdjpldvfoceccymsvvqmuocbwgknzwuwzfnmjirzmvdqtsirnafkrhlnp"};
	vector<vector<char> > b1_v = buildBoard(b1, 97, 71);;
	string s1("cptynvechpk");

	cout << s.exist(b1_v, s1);
}
