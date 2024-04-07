#include <iostream>
#include <string>
#include "functions.cpp"
#include <fstream>
#include "clubinfo.h"
#include "addentry.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BLACK       "\033[30m"
#define BOLD_BLACK  "\033[1m\033[30m"
#define BOLD_RED    "\033[1m\033[31m"
#define BOLD_GREEN  "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE   "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN   "\033[1m\033[36m"
#define BOLD_WHITE  "\033[1m\033[37m"
#define BG_BRIGHT_BLACK     "\033[100m"
#define BG_BRIGHT_RED       "\033[101m"
#define BG_BRIGHT_GREEN     "\033[102m"
#define BG_BRIGHT_YELLOW    "\033[103m"
#define BG_BRIGHT_BLUE      "\033[104m"
#define BG_BRIGHT_MAGENTA   "\033[105m"
#define BG_BRIGHT_CYAN      "\033[106m"
#define BG_BRIGHT_WHITE     "\033[107m"
#define BRIGHT_BLACK        "\033[90m"
#define BRIGHT_RED          "\033[91m"
#define BRIGHT_GREEN        "\033[92m"
#define BRIGHT_YELLOW       "\033[93m"
#define BRIGHT_BLUE         "\033[94m"
#define BRIGHT_MAGENTA      "\033[95m"
#define BRIGHT_CYAN         "\033[96m"
#define BRIGHT_WHITE        "\033[97m"


using namespace std;

int main()
{
    std::cout << endl;
    std::cout <<BOLD_YELLOW<< "======================================= Welcome to DA_IICT CLUB MANAGER =======================================" <<RESET<< endl;
    string file_name;

item:
    std::cout << endl;
    std::cout << "Enter the file name from which data will be loaded into the programme. (Use the extension .txt also): ";
    cin >> file_name;
    ifstream fin;
    fin.open(file_name, ios::in);

    if (!fin && !fin.eof())
    {
        std::cout << endl;
        std::cout <<RED<< "File does not exist or file is empty" <<RESET<< endl;
        std::cout <<BRIGHT_RED<< "Press 0 to exit or Press 1 to continue and give file name again: ";
        int k;
        cin >> k;

        if (k == 0)
        {
            return 0;
        }
        else
        {
            goto item;
        }
    }

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> list;
    unordered_multimap<string,long long> na_id;

    auto temp = load_data(file_name); // All the data from file gets loaded into the unordered map

    list = temp.first;

    na_id = temp.second;

    int b = 1;
    cout <<GREEN<< "File Uploaded successfully..!!" <<RESET<< endl;
    while (b == 1)
    {
         std::cout << endl;
         std::cout <<BOLD_MAGENTA<< "Please follow the following menu" <<RESET<< endl;
         std::cout <<BOLD_MAGENTA<< "--------------------------------" <<RESET<< endl;
         std::cout << BLUE << BOLD << "1. All club members of a particular club." << RESET << endl;
         std::cout << BLUE << BOLD << "2. To get the details of all members." << RESET << endl;
         std::cout << BLUE << BOLD << "3. To get details of club." << RESET << endl;
         std::cout << BLUE << BOLD << "4. To search any club member." << RESET << endl;
         std::cout << BLUE << BOLD << "5. To become a member in any club." << RESET << endl;
         std::cout << BLUE << BOLD << "6. To leave any club." << RESET << endl;
         std::cout << BLUE << BOLD << "7. To exit." << RESET << endl;
         std::cout << "Enter Choice: ";
        int menu;
        cin >> menu;
        switch (menu)
        {

        case 1:
        {
            std::cout << endl;
            std::cout <<BRIGHT_RED<< "Please enter the club name(You may type the name only and no need for the word CLUB, only for developer student club type DSClub): "<<RESET<<endl;
            string club;
            cin >> club;
            mem_club(list, club);

            break;
        }

        case 2:
        {
            std::cout <<YELLOW<< "All the club member details are as follows: " <<<RESET< endl;
            get_all_mem(list);
            break;
        }

        case 3:
        {
            std::cout << endl;
            std::cout <<BOLD_BLUE<< "Please follow the following menu to fetch information about any club: " <<RESET<< endl;
            std::cout <<BOLD_BLUE<< "---------------------------------------------------------------------" <<RESET<< endl;
            std::cout << left << setw(30) << "1.Radio Club" << setw(30) << "2.Sambhav" << setw(30) << "3.Business Club" << setw(30) << "4.DCEI" << endl
                      << left << setw(30) << "5.CINS" << setw(30) << "6.Webkit Club" << setw(30) << "7.Muse Club" << setw(30) << "8.Debate Club" << endl
                      << left << setw(30) << "9.Music Club" << setw(30) << "10.Developer Student Club" << setw(30) << "11.Chess Club" << setw(30) << "12.Press Club" << endl
                      << left << setw(30) << "13.IEEE" << setw(30) << "14.Film Club" << setw(30) << "15.Research Club" << setw(30) << "16.Programming Club" << endl
                      << left << setw(30) << "18.Khelaiya Club" << setw(30) << "19.Cubing Club" << setw(30) << "20.Excursion Club" << setw(30) << "21.BIS club" << endl
                      << left << setw(30) << "17.PMMC" << setw(30) << "22.Heritage Club" << setw(30) << "23.Electronic Hobby Centre" << setw(30) << "24.Headrush-quizzing" << endl
                      << left << "25.DAIICT Theatre Group" << endl;

            int c1;
            do
            {
                int r;
                std::cout <<BRIGHT_GREEN<< "Enter Your choice: ";
                cin >> r;
                info(r);
                std::cout <<BRIGHT_BLUE<< "If you again want information, press 1 or Press 0 if you do not want any info: ";
                cin >> c1;
            } while (c1 == 1);
            break;
        }

        case 4:
        {
            search(list,na_id);
            break;
        }
        case 5:
        {
            addentry(list);
            break;
        }
        case 6:
        {
            del_entry(list);
            break;
        }
        case 7:
        {
            reload_data(list,file_name);
            return 0;
        }
        }
    }
}




//-----------------------------------------------------------------------------------------changedclubinfo


#include <iostream>
using namespace std;
void radioclub_info()
{
    cout <<BLUE << "   ------------------" <<RESET<<endl;
    cout <<GREEN<< "--> Radio Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Radio Club is a hobby club at DAIICT, Gujarat, India. Radio Club makes podcasts, shows"
         << "interviews and other radio sessions brought to you by the enthusiastic students of the institute"
         << "It is a small group of people, who collectively try to emulate the real life radio shows, allowing people to speak their minds and have fun meanwhile."
         << "We have a few RJs, who talk about different topics and current events going on in the college." << endl;
}
void sambhav_info()
{
    cout <<BLUE<< "    ---------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Sambhav Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ---------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Sambhav means possible. Sambhav, at DA-IICT is a group of students with interest or urge to"
         << "bring some positive change in the society. Sambhav organises various activities throughout a year."
         << "Book Sale is one of our main activities where we sell old unused books at heavily discounted prices to students who wish"
         << "to purchase them. We organise visits to nearby Orphanage and Deaf and Dumb School. These visits make students aware of the"
         << "society they live in, making them more attached to various sections of the society as well as generate a sense of responsibility"
         << ".Another major event which we organise is the Blood Donation Camp where we organise a camp in the college"
         << "itself, giving an opportunity the youth of today a chance to serve the society. Sambhav strives to develop a positive"
         << "and empathetic attitude in students towards the society which they are a part of. Sambhav grows, adopts and adapts"
         << "thus attaining the sense of We Make It Sambhav" << endl;
}
void businessclub_info()
{
    cout <<BLUE<< "    --------------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Businessclub club detials: " <<RESET<< endl;
    cout <<BLUE<< "    --------------------------" <<RESET<< endl;
    cout << endl;
    cout << "       The Business Club consist of individuals who possess a genuine enthusiasm for the dynamics of wealth"
         << "creation and a thirst for knowledge, regardless of their current level of expertise."
         << "In addition to financial acumen, we have proactive members who can infuse fresh, creative ideas into our community."
         << "Our mission is to reshape the business landscape at our university.You can also join the Business Club and Cultivate a Passion"
         << "for Finance, Innovation, and Entrepreneurship!" << endl;
}
void DCEI_info()
{
    cout <<<BLUE< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> DCEI Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Hello all, we are DA-IICT Centre for Entrepreneurship and Incubation. We're here to help you turn your ideas"
         << "into reality. As representatives of DCEI, we're passionate about promoting innovation, entrepreneurship, and problem-solving."
         << "Join us to ignite your entrepreneurial spirit!Many of you must have seen shows like Shark Tank and hoped to become part"
         << "of something like that.Well, no worries, as we have events like At DA Tank where you'll have the chance to pitch your own"
         << "entrepreneurial ideas to seasoned industry pros." << endl;
}
void CINS_info()
{
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> CINS Club detials: " <<RESET<<endl;
    cout <<BLUE<< "    ------------------" <<RESET<<endl;
    cout << endl;
    cout << "       We are the Cyber Security Club. We are driven by the amazing passion of students of Cyber Information and Network Security"
         << "Club. We also organise different cyber security events that promises to test your skills, challenge your "
         << "knowledge, and provide an opportunity to learn and connect with fellow enthusiasts. We will take cyber security into storm." << endl;
}
void DSClub_info()
{
    cout <<BLUE<< "    --------------------" <<RESET<< endl;
    cout <<GREEN<< "--> DSClub Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    --------------------" <<RESET<< endl;
    cout << endl;
    cout << "       We are a chapter of Google Developer Groups, which has numerous chapters all over the globe. DA-IICT is"
         << "one of the very few colleges in India which has its own chapter. We are a group of technology enthusiasts who aim to"
         << "inculcate a healthy developing culture in our college community, by acquainting people with the most essential and also"
         << "the latest Tools and Technologies.Our prime focus revolves around technologies developed by Google, we do"
         << "explore into other open source technologies such as Git. We at GDG, welcome people who have passion for"
         << "technology and want to develop something tangible." << endl;
}
void Webkitclub_info()
{
    cout <<BLUE<< "    --------------------" <RESET< endl;
    cout <<GREEN<< "--> Webkit Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    --------------------" <<RESET<< endl;
    cout << endl;
    cout << "       The WebKit club is a student community of Web development enthusiasts, interested both in creating and maintaining codes"
         << "as well as building and expanding a stronger community of like minded students. As the name suggests ,we are about all things web."
         << "The club motivates budding Web developers by organizing technical sessions and camps to introduce and help them learn new"
         << "Web Technologies like HTML5, CSS3, JavaScript, ReactJS, VueJS, Firebase and many more. Our premier event, The WebDev Camp"
         << "is organized every semester for students interested in learning Web Development by helping them build a production ready"
         << "application from scratch." << endl;
}
void filmclub_info()
{
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Film Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       By far the most celebrated club, the Film Club occupies a special place in every student heart. The club was started"
         << "by a few movie enthusiasts with the aim of providing regular entertainment to DA-IICTians in the form of interesting as"
         << "well as enlightening cinema. The club screens a movie the night before every regular holiday (Saturdays and Sundays) and"
         << "Screens Matches(Cricket, Football,etc) at the Open Air Theatre (OAT). The Film Club has a wide range of movies 250 English"
         << "170 Hindi and 25 Other, and is also continually being increased regularly. Bears ample testimony to the fact that the club"
         << "can boast not only of quantity, but also of quality. Keeping all interests in mind, the club has something for each student"
         << "of DAIICT. From Shutter Island to Guide, from 3 Idiots to Devdas, the movies cater to multiple and varied backgrounds." << endl;
}
void Press_info()
{
    cout <<BLUE<< "    -------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Press Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -------------------" <<RESET<< endl;
    cout << endl;
    cout << "       As the journalism cell of DAIICT, The Press Club strives to give voice to the student community and"
         << "aspires to be a podium to lodge campus musings in all its moods. To achieve its maxim, The Press Club engages in a"
         << "number of journalistic undertakings in the campus. Its principal product is Entelechy, DAIICT’s only campus magazine."
         << "Entelechy, the student-run magazine of DA, has over the years and over its editions, morphed into a voice, a power, a passion"
         << "and an endeavor in the verve of those it envelops, and that is what makes Entelechy more than a magazine. Entelechy is, to us,"
         << "a concept of volition; it is the autonomy of thought and an enticement to ingenuity. We, at the Press Club, aspire to make a"
         << "difference in the littlest way we can." << endl;
}
void musicclub_info()
{
    cout <<BLUE<< "    -------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Music Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -------------------" <<<RESET< endl;
    cout << endl;
    cout << "       The Music Club of DA-IICT aims to develop an interest in students towards music and create a healthy music"
         << "atmosphere amongst the student community. To achieve this purpose, we organise various Acoustic Nite Lives for"
         << "the students to perform with their friends or other music enthusiasts. We also form teams to compete in various music"
         << "competitions in the annual cultural festivals of various prestigious institutes throughout the year. One of the major"
         << "events which we perform in is the Ragnarock. Apart from this, we strive to organise various informal jamming sessions"
         << "where a group of students just gets together and sings its heart out. The sole vision of the Music Club is to keep"
         << "the music taste, talent and atmosphere alive in the music enthusiasts of DAs student community and to provide platforms"
         << "to nurture this talent." << endl;
}
void DAIICT_Theatreclub_info()
{
    cout <<<BLUE< "    ----------------------------" <<RESET<< endl;
    cout <<<GREEN< "--> DAIICT_Theatre Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------------------" <<RESET<< endl;
    cout << endl;
    cout << "       DAIICT Theatre Group, aka DTG, is a club that conducts and administers theatrics events of DAIICT. There are"
         << "no bounds to the form of theatre that we perform, having ventured through stage plays, nukkad natak, mime, mono-acting,"
         << "mimicries, musical plays, and what not, for which numerous learning and performing workshops are regularly conducted."
         << "We do not only have performers, but also wonderful script writers, directors, composers, etc., but first, we are a group"
         << "of crazy and dedicated learners. We live our hearts out on the stage. The club has always been equally enthusiastic to"
         << "welcome the new faces as it is with present members. In fact the main essence of DTG is being an open club and thus it"
         << "is a family to us rather than just a club. Life is a stage and we all are actors." << endl;
}
void researchclub_info()
{
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Research Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------------" <<<RESET< endl;
    cout << endl;
    cout << "       DA-IICT boasts of being a research-oriented institute and the Research Club aims to work to foster a"
         << "community within the college for those interested in research. It works to help those interested in research,"
         << "particularly starting at the Bachelor level; be it to find others working in similar areas or to organize on"
         << "-campus seminars and other opportunities for students to get to know the kind of research that is prevalent."
         << "The Research Club would eventually like to be a small cog that enables the functioning of an active and interdisciplinary"
         << "research community within DA-IICT." << endl;
}
void chessclub_info()
{
    cout <<BLUE<< "    -------------------" <<RESET<<>> endl;
    cout <<GREEN<< "--> Chess Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -------------------" <<RESET<< endl;
    cout << endl;
    cout << "       As the name suggests, we are a group of enthusiastic people who are mad about chess. Chess club focuses on"
         << "enhancing the skills of the students having interest in chess. We provide them proper guidance about tactics and"
         << "other aspects of the game ,We encourage them to develop their skills and provide"
         << "them platform by conducting various tournaments and making them participate in inter college tournaments"
         << "Chess club focuses on enhancing the skills of the interested members having interest in chess." << endl;
}
void programmingclub_info()
{
    cout <<BLUE<< "    -------------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Programming Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -------------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Programming Club has been working to help people explore their hidden passion for programming. We help"
         << "students understand some basic concepts and few who stick around enjoy and master the art competitive programming."
         << "This includes solving complex problems under some time and space constraints, which is a valued skill in the field"
         << "of computer science. Our philosophy is to make programming a fun activity where students come up with problems"
         << "and discuss solutions out of their interest. We regularly organize contests and discussion sessions to encourage"
         << "participation of the student community. We actively promote students to participate in algorithmically challenging "
         << "competitions like ACM ICPC, Facebook Hacker-cup, Google Code Jam, Codechef Snackdown, TCS Codevita, Hackerearth "
         << "Collegiate Cup and various others. Students of our club have represented DA-IICT at various such competitions."
         << "Programming club continuously strives to uphold and further raise the bar for the programming capabilities of "
         << "students at DA-IICT." << endl;
}
void khelaiyaclub_info()
{
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Khelaiya Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Folk dance is where the culture breaths.” Khelaiya club- DAIICT provides a medium and platform to express "
         << "through the art of folk dance and thus strives to keep the culture of folk dance alive. The khelaiya club organises "
         << "workshops for the Garba enthusiasts to engage them in the subtle art of Garba during Navratri. The Khelaiya club "
         << "also participates in various events throughout the year. We at Khelaiya club, desire to bring together people "
         << "and help them live their dance dream" << endl;
}
void cubingclub_info()
{
    cout <<BLUE<< "    --------------------" <<<RESET< endl;
    cout <<GREEN<< "--> Cubing Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    --------------------" <<RESET<< endl;
    cout << endl;
    cout << "       It is a community by and for people interested in solving Rubiks Cube and its other cubic and non-cubic "
         << "variants. We promote cubing by speedcubing sessions and organizing various competitions(general and WCA affiliated). "
         << "We do Mosaic construction using cubes and imitate many renowned artists using the art of cubers at DAIICT, cubing way of "
         << "giving tribute to anyone." << endl;
}
void PMMC_info()
{
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> PMMC Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       PMMC or Photography and moviemaking club as the name suggest we are the photographer and video makers."
         << "We, as the members of the club, seek to display our love of photography through capturing our college's events and "
         << "festivals. To encourage people we organize Photo and Design Exhibitions, Photography walks, sessions on photography "
         << "and film making, also tries to provide hands on sessions. PMMC strives to capture the happiest moments of our college life." << endl;
}
void excursionclub_info()
{
    cout <<BLUE<< "    -----------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Excursion Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -----------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Excursions are the activities which every engineering student is most awaited of. These "
         << "become the most memorable moments of ones life when we travel with our friends. We, the Excursion "
         << "club of DA-IICT plan and organise such trips for you and gives you a stack of unforgettable moments "
         << "you have spent with your pals." << endl;
}
void electronics_hobby_info()
{
    cout <<BLUE<< "    -----------------" <<RESET<< endl;
    cout <GREEN<< "--> EHC Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -----------------" <<RESET<< endl;
    cout << endl;
    cout << "       We, the EHC, as a group of enthusiastic electronics students aim to maintain and grow the culture of electronics "
         << "in the campus of DA-IICT. We believe that for excellence in any field, it is necessary that student has strong roots in "
         << "terms of knowledge. With this idea, we assume basic electronic sessions for freshers in electronics. These hands on sessions,"
         << "not only help students to have a thorough understanding of the subject, but also help them developing better understanding "
         << "of what they are studying in the lectures. For students, who are thrilled by electronics or have amazing innovative ideas "
         << "for projects, we support them for their adventures, in terms of resources, and guidance. We also have our won teams keep "
         << "working on interesting projects. Apart from these ventures, we prepare freshers to participate in various university "
         << "electronics competitions. With all these efforts, we thrive to motivate students, as a whole community to develop a fresh "
         << "perspective for electronics." << endl;
}
void debateclub_info()
{
    cout <<BLUE<< "    -------------------" <<RESET<, endl;
    cout <<GREEN<< "--> Debat Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -------------------" <<RESET<< endl;
    cout << endl;
    cout << "       We are a group of people who like to talk, who believe in the power of words to bring about change, "
         << "who promote dissent and discussion. We do this by conducting weekly sessions of Parliamentary Debating and "
         << "Group Discussions on all kinds of topics ranging from politics to movies to morality and ethics. We also "
         << "have Open Forum Discussions, a platform for the faculty and students to interact on topics affecting both "
         << "as well as MUNs (Model United Nations). The Debate Club strives to inculcate a culture of dissension while "
         << "everyone has a good time." << endl;
}
void heritageclub_info()
{
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Heritage Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Our mission is to “Have every child, experience the inspiration and mysticism embodied in Indian and "
         << "world heritage”. We organize different events, categorized into two parts: local events and other events. "
         << "Local events include workshops, training, demonstrations and other techniques to get the student an idea "
         << "on the cultural part of art forms. We believe every child has the capability of some or the other art form. "
         << "We not only include events on singing and dancing, but also take into consideration the other art forms such "
         << "as painting, pottery, poetry etc." << endl;
}
void headrush_info()
{
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Headrush Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Headrush is the quizzing club of DA-IICT. We are a group of quizzing enthusiasts that aim to not "
         << "only maintain but perpetually ascertain the growth of the level of comepetitive quizzing in the college "
         << "while providing a platform for leisurely quizzers to enjoy intense and entertataining weekly quiz sessions "
         << "ranging across a plethora of topics like ent, music, lit, sci-tech, biz etc." << endl;
}
void BISclub_info()
{
    cout <<BLUE<< "    -----------------" <<RESET<< endl;
    cout <<GREEN<< "--> BIS Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    -----------------" <<RESET<< endl;
    cout << endl;
    cout << "       You can have the chance of shaping the future of technology and safety. Join the Bureau Of Indian Standards"
         << "Club and collaborate with industry experts, contribute to national standards and gain hands-on experience in emerging fields like"
         << "drones and robotics. Network, Learn, Lead. BIS Club conducts events related to product standards in technnology and visits"
         << "are conducted for the club at different product manufacturing companies" << endl;
}
void IEEEclub_info()
{
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> IEEE Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       IEEE student branch of DAIICT focuses on enhancing the learning experience of the student community. IEEEs"
         << "main focus is to foster technological innovation and excellence for the benefit of humanity. We focus on conducting"
         << "social and technical activities for students and encourage them to take full advantage of IEEE membership like"
         << "scholarships, competitions, seminar and conference grants. We have 2 Special Interest Groups (SIG): SIG- Moblie"
         << "Apps and SIG- Embedded. SIG- Moblie Apps conduct weekly workshops on Android application development and SIG- Embedded"
         << "conducts weekly sessions on embedded hardware like Arduino. We IEEE SB members at DA-IICT regularly conduct workshops"
         << "such as line follower and manual robotics workshop. Women in Engineering(WIE) is also a part of IEEE. It is dedicated"
         << "to promoting women engineers and scientists. It is a platform where men and women collectively use their diverse talents"
         << "to innovate for the benefit of humanity. Industrial applications society is a global society of IEEE, which provides"
         << "industrial exposure to students. We boast our technical fest called i.Fest which we organize every year. It consists"
         << "of various challenging and competitive events where students from in and around DA-IICT come to participate." << endl;
}
void museclub_info()
{
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout <<GREEN<< "--> Muse Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ------------------" <<RESET<< endl;
    cout << endl;
    cout << "       Welcome aboard the Muse Club express, where the creative vibes are high and the fun is even higher!"
         << "We're a bunch of design fanatics who believe that art is all about letting loose and having a blast. Doodles,"
         << "sketches, and art galore - that's our language! We provide you the ultimate chance to flaunt your wild imagination and unique"
         << "style through doodles. Forget rules, forget limits, it's your time to shine!" << endl;
}

void AIclub_info()
{
    cout <<BLUE<< "    ----------------" <<RESET<< endl;
    cout <<GREEN<< "--> AI Club detials: " <<RESET<< endl;
    cout <<BLUE<< "    ----------------" <<RESET<< endl;
    cout << endl;
    cout << "       We are on a mission to educate others about AI and its applications. We are a bunch of ML(Machine Learning) Enthusiasts"
         << ". We also arrange prompt conteests in which studentss may imagine the wildest, most impossible scenarios and then "
         << "convert them into digital art. We try to build a healthy community of AI/ML practitioners at DAIICT." << endl;
}

void info(int r)
{

    switch (r)
    {
    case 1:
    {
        radioclub_info();
        break;
    }
    case 2:
    {
        sambhav_info();
        break;
    }
    case 3:
    {
        businessclub_info();
        break;
    }
    case 4:
    {
        DCEI_info();
        break;
    }
    case 5:
    {
        CINS_info();
        break;
    }
    case 6:
    {
        Webkitclub_info();
        break;
    }
    case 7:
    {
        museclub_info();
        break;
    }
    case 8:
    {
        debateclub_info();
        break;
    }
    case 9:
    {
        musicclub_info();
        break;
    }
    case 10:
    {
        DSClub_info();
        break;
    }
    case 11:
    {
        chessclub_info();
        break;
    }
    case 12:
    {
        Press_info();
        break;
    }
    case 13:
    {
        IEEEclub_info();
        break;
    }
    case 14:
    {
        filmclub_info();
        break;
    }
    case 15:
    {
        researchclub_info();
        break;
    }
    case 16:
    {
        programmingclub_info();
        break;
    }
    case 17:
    {
        PMMC_info();
        break;
    }
    case 18:
    {
        khelaiyaclub_info();
        break;
    }
    case 19:
    {
        cubingclub_info();
        break;
    }
    case 20:
    {
        excursionclub_info();
        break;
    }
    case 21:
    {
        BISclub_info();
        break;
    }
    case 22:
    {
        heritageclub_info();
        break;
    }
    case 23:
    {
        electronics_hobby_info();
        break;
    }
    case 24:
    {
        headrush_info();
        break;
    }
    case 25:
    {
        DAIICT_Theatreclub_info();
        break;
    }
    case 26:
    {
        AIclub_info();
        break;
    }
    }
}


//----------------------------------------------------------------------------changedfunction

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Assumption : file is prechecked. file exist or not

string club[] = {"AI", "Dance", "Research", "Chess", "Cubing", "Excursion", "Microsoft", "Radio", "DCEI", "Sambhav",
                 "Developer_Studen", "WebKit", "Business", "BIS", "Debate", "Music", "Programming", "IEEE", "Heritage", "Headrush_Quizzing",
                 "Muse", "Press", "DAIICT_Theatre", "Film", "Khelaiya", "EHC", "PMMC", "CINS"};

pair<unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>>,unordered_multimap<string,long long>> load_data(string file_name)
{
    ifstream fin;
    fin.open(file_name, ios::in);

    int c,a;
    long long id, number;
    string name, club_name, position, temp2;

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;
    unordered_multimap<string,long long> na_id;

    while (fin >> club_name >> id >> name >> temp2 >> number >> position)
    {
        name = name + " " + temp2;
        directory[club_name][id] = make_pair(name, make_pair(number, position));

        a=0;
        c= na_id.count(name);
        if(c>0){
            auto range = na_id.equal_range(name);

            for(auto person = range.first ; person != range.second ; ++person){
                if(person->second==id){
                    a=1;
                }
            }
        }

        if(c==0 ||  a==0){
            na_id.insert({name,id});
        }
    }

    fin.close();

    return make_pair(directory,na_id);
}

void mem_club(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string club_name)
{
    std::cout << endl;
    int n = 0;
    for (auto dir : directory[club_name])
    {
        if (n == 0)
        {
            std::cout <<CYAN<< "================ "<< club_name << CYAN<< " Club member detials ================" <<RESET<< endl;
            std::cout <<YELLOW<< left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" <<RESET<< endl;
            std::cout <<BRIGHT_GREEN<< "-----------------------------------------------------------" <<RESET<< endl;
            std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
            n++;
        }
        else
        {
            std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
            n++;
        }
    }
    if (n == 0)
    {
        std::cout <<LIGHT_YELLOW<< "There are no member in " << club_name << " ..!!" <<RESET<< endl;
    }
    std::cout << "------------//--------------//-------------//--------------" << endl;
    std::cout << endl
              << endl;
}

void get_all_mem(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory)
{
    cout << endl;
    int n;
    for (int i = 0; i < 28; i++)
    {
        if (!directory[club[i]].empty())
        {
            std::cout <<YELLLOW<< "=> " << club[i] << " Club :" <<RESET<< endl;
            std::cout <<BLUE<< left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" <<RESET<< endl;
            std::cout <<MAGENTA<< "-----------------------------------------------------------" <<RESET<< endl;
            n = 1;
            for (auto dir : directory[club[i]])
            {
                std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
                n++;
            }
            std::cout << "------------//--------------//-------------//--------------" << endl;
            std::cout << endl
                      << endl;
        }
    }
}

void find_by_id(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, long long id)
{
    std::cout << endl;
    int a = 0, n = 1;
    for (int i = 0; i < 28; i++)
    {
        auto person = directory[club[i]].find(id);
        if (person != directory[club[i]].end())
        {
            a++;
            if (a == 1)
            {
                std::cout <<BOLD_BLUE<< "===============================Student Detials================================" <<RESET<< endl;
                std::cout <<GREEN<< left << setw(15) << "Student ID" << setw(20) << "Student Name" << setw(20) << "Contact Number" << setw(15) << "Joined Club" << setw(15) << "Position" <<RESET<< endl;
                std::cout << "------------------------------------------------------------------------------" << endl;
                std::cout << setw(15) << person->first << setw(20) << person->second.first << setw(20) << person->second.second.first << setw(15) << club[i] << setw(15) << person->second.second.second << endl;
                n++;
            }
            else
            {
                std::cout << right << setw(62) << club[i] << right << setw(14) << person->second.second.second << endl;
                n++;
            }
        }
    }
    if (a == 0)
    {
        std::cout <<RED<< "Person not found..!!" <<RESET<< endl;
        return;
    }
    std::cout << "------//----------//----------//-----------//-----------//-----------//-------";
    std::cout << endl
              << endl;
}

void find_by_contact(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, long long number)
{
    int count = 0;
    long long id;
    for (int i = 0; i < 28; ++i)
    {

        for (auto element : directory[club[i]])
        {

            if (number == element.second.second.first)
            {
                id = element.first;
                count++;
                find_by_id(directory, id);
                return;
            }
        }
    }
    if (count == 0)
    {
        std::cout <<RED<< "Person Not Found..!!" <<RESET<< endl;
        std::cout << endl;
    }
}

void find_by_name(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string name,unordered_multimap<string,long long> &na_id)
{
    long long id;
    int count;

    count= na_id.count(name);

    if (count == 0)
    {
        std::cout <<RED<< "Person not found..!!" <<RESET<< endl;
        std::cout << endl;
        return;
    }
    else if (count == 1)
    {
        auto temp = na_id.find(name);
        id = temp->second;
        find_by_id(directory,id);
    }
    else if (count == 2)
    {
        std::cout <<BRIGHT_YELLOW<< "Here we got more than one result..!!" <<RESET<< endl;
        std::cout <<BRIGHT_YELLOW<< "We want some additional information" <<RESET<< endl;
        std::cout << endl;

    lable:

        std::cout <<BRIGHT_CYAN<< "1. to show all results" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "2. to find through id" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "3. to find through contact number" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "4. to find through club name" <<RESET<< endl;
        std::cout << "Enter Choice: ";
        int a;
        cin >> a;
        if (a == 1)
        {
            auto temp = na_id.equal_range(name);

            for(auto person = temp.first; person != temp.second;++person){
                id=person->second;
                find_by_id(directory,id);
            }

        }
        else if (a == 2)
        {
            long long b;
            std::cout << "Enter Student id: ";
            cin >> b;
            find_by_id(directory, b);
        }
        else if (a == 3)
        {
            long long number;
            std::cout << "Enter number: ";
            cin >> number;
            find_by_contact(directory, number);
        }
        else if (a == 4)
        {
            long long id;
            int c = 0;
            string cl;
            std::cout << "Enter club name: ";
            cin >> cl;

            for (auto element : directory[cl])
            {
                if (name == element.second.first)
                {
                    if (c == 0)
                    {
                        c++;
                        id = element.first;
                    }
                    else if (c == 1)
                    {
                        if (id != element.first)
                        {
                            c++;
                            break;
                        }
                    }
                }
            }

            if (c == 0)
            {
                std::cout << endl;
                std::cout <<YELLOW<< "You provided wrong club name" <<RESET<< endl;
                std::cout <<YELLOW<< "Please enter some other detail" <<RESET<< endl;
                std::cout << endl;
                goto lable;
            }
            else if (c == 1)
            {
                find_by_id(directory, id);
            }
            else if (c == 2)
            {
                std::cout << endl;
                std::cout << "We got more than one person with same name present in " << cl << " club " << endl;
                std::cout << "We want some additional information" << endl;
                std::cout << endl;
                std::cout <<BRIGHT_GREEN<< "1. to show all result"<<RESET<< endl;
                std::cout <<BRIGHT_GREEN<< "2. to give id" <<RESET<< endl;
                std::cout <<BRIGHT_GREEN<< "3. to give contact number" <<RESET<< endl;
                std::cout << "Enter choice: ";
                int g;
                cin >> g;

                if (g == 1)
                {
                    for (auto element : directory[cl])
                    {
                        if (name == element.second.first)
                        {
                            id = element.first;
                            find_by_id(directory, id);
                        }
                    }
                }
                else if (g == 2)
                {
                    long long id;
                    cin >> id;

                    find_by_id(directory, id);
                }
                else if (g == 3)
                {
                    long long number;
                    cin >> number;

                    find_by_contact(directory, number);
                }
            }
        }
    }
}

void search(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory ,unordered_multimap<string,long long> &na_id)
{
    std::cout << endl;
    std::cout <<MAGENTA<< "1. to search by id" <<RESET<< endl;
    std::cout <<MAGENTA<< "2. to search by name" <<RESET<< endl;
    std::cout <<MAGENTA<< "3. to search by contact number" <<RESET<< endl;
    std::cout << "Enter choice: ";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
    {
        std::cout << endl;
        std::cout << "Enter student id: ";
        long long id;
        cin >> id;
        std::cout << endl;
        find_by_id(directory, id);
    }
    else if (a == 2)
    {
        std::cout << endl;
        std::cout << "Enter name: ";
        string name;
        getline(cin, name);
        std::cout << endl;
        find_by_name(directory, name,na_id);
    }
    else if (a == 3)
    {
        std::cout << endl;
        std::cout << "Enter contact number: ";
        long long number;
        cin >> number;
        std::cout << endl;
        find_by_contact(directory, number);
    }
}

void del_entry(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory)
{
    std::cout << endl;
    string temp, club;
    std::cout << "What made you to leave this club: ";
    std::getline(cin, temp);
    std::cin.ignore();
    long long id;
label:
    std::cout << endl;
    std::cout << "Please enter your id: ";
    cin >> id;
    cout << "Please enter Your name: ";
    cin >> club;
    if (directory[club].find(id) != directory[club].end())
    {
        directory[club].erase(id);
    }
    else
    {
        std::cout <<RED<< "You have entered wrong club name or id..!!" <<RESET<< endl;
        goto label;
    }
}

void reload_data(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string file_name)
{
    ofstream fout;
    fout.open(file_name, ios::out);
    string name, position;
    long long id, number;

    for (int i = 0; i < 28; ++i)
    {

        if (!directory[club[i]].empty())
        {

            for (auto person : directory[club[i]])
            {

                id = person.first;
                name = person.second.first;
                number = person.second.second.first;
                position = person.second.second.second;

                fout << club[i] << " " << id << " " << name << " " << number << " " << position << endl;
            }
        }
    }
    fout.close();
}

// int main()
// {

//     unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;

//     directory = load_data("test.txt");

//     search(directory);

//     //mem_club(directory, "CINS");

//     //get_all_mem(directory);

//     //find_by_id(directory, 202303042);

//     // find_by_name(directory, "Manan Chhabhaya");
//     //find_by_name(directory, "Vraj Patel");
//     return 0;
// }


//--------------------------------------------------------------------------------ADDENTRY.H


#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

void add(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory,string club_name)
{
cout<<GREEN<<"Welcome to the "<<club_name<< "club"<<RESET<<endl;
cout<<BRIGHT_CYAN<<"Enter your full name"<<<RESET<endl;
string name;
cin.ignore();
getline(cin,name);
cout<<BRIGHT_CYAN<<"Enter ID"<<RESET<<endl;
long long id,contact;
cin>>id;
cout<<BRIGHT_CYAN<<"Enter Contact Number"<<RESET<<endl;
cin>>contact;
string pos="Member";
directory[club_name][id]=make_pair(name,make_pair(contact,pos));
}


void addentry(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> dire)
{
    cout<<MEGENTA<<"Enter the number of the club in which you want to get added"<<RESET<<endl;

    cout<<"Please follow the following menu clubs"<<endl
            <<"1.Radio Club  2.Sambhav  3.Business Club  4.DCEI"<<endl
            <<"5.CINS  6.Webkit Club  7.Muse Club  8.Debate Club  9.Music Club"<<endl
            <<"10.Developer Student Club  11.Chess Club  12.Press Club  13.IEEE"<<endl
            <<"14.Film Club  15.Research Club  16.Programming Club  17.PMMC"<<endl
            <<"18.Khelaiya Club  19.Cubing Club  20.Excursion Club  21.BIS club"<<endl
            <<"22.Heritage Club  23.Electronic Hobby Centre  24.Headrush-quizzing"<<endl
            <<"25.DAIICT Theatre Group 26.AI Club"<<endl;
        int c2;
        int x;
        cin>>x;
        do 
        {
        switch(x)
        {
            case 1:
            {
                int a1,a2,a3;
                cout<<"Have you heard any news, speech from radio in the past? (YES - 1 and NO - 0)"<<endl;
                cin>>a1;
                cout<<"Do you have interest in writing poems, giving speeches? (YES - 1 and NO - 0)"<<endl;
                cin>>a2;
                cout<<"Do you love graphic designing? (YES - 1 and NO - 0)"<<endl;
                cin>>a3;
                if(a1 && a2 && a3)
                {
                    add(dire,"Radio");
                }
                else
                {
                    cout<<RED<<"Sorry, you are not eligible for radio club"<<RESET<<endl;
                }
                break;
            }
            case 2:
            {
                int b1,b2,b3;
                cout<<"Do you have interest in contributing for society? (YES - 1 and NO - 0)"<<endl;
                cin>>b1;
                cout<<"Can you spare time for social activities? (YES - 1 and NO - 0)"<<endl;
                cin>>b2;
                cout<<"Do you want to make it possible? (YES - 1 and NO - 0)"<<endl;
                cin>>b3;
                 if(b1 && b2 && b3)
                {
                    add(dire,"Sambhav");
                }
                else
                {
                    cout<<RED<<"Sorry, you are not eligible for Sambhav at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 3:
            {
                int c1,c2,c3;
                cout<<"Do you have a business mind? (YES - 1 and NO - 0)"<<endl;
                cin>>c1;
                cout<<"Do you have fresh ideas to induce in business community? (YES - 1 and NO - 0)"<<endl;
                cin>>c2;
                cout<<"Can you take risk? (YES - 1 and NO - 0)"<<endl;
                cin>>c3;
                if(c1 && c2 && c3)
                {
                    add(dire,"Business");
                }
                else
                {
                     cout<<RED<<"Sorry, you are not eligible for Business club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 4:
            {
                int d1,d2,d3;
                cout<<"Do you have interest in contributing for society? (YES - 1 and NO - 0)"<<endl;
                cin>>d1;
                cout<<"Can you spare time for social activities? (YES - 1 and NO - 0)"<<endl;
                cin>>d2;
                cout<<"Do you want to make it possible? (YES - 1 and NO - 0)"<<endl;
                cin>>d3;
                if(d1 && d2 && d3)
                {
                    add(dire,"DCEI");
                }
                else
                {
                     cout<<RED<<"Sorry, you are not eligible for DCEI club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 6:
            {
                int e1,e2,e3;
                cout<<"Do you have interest in development? (YES - 1 and NO - 0)"<<endl;
                cin>>e1;
                cout<<"Are you interested in exploring new web technologies? (YES - 1 and NO - 0)"<<endl;
                cin>>e2;
                cout<<"Are you willing to make a future in this branch? (YES - 1 and NO - 0)"<<endl;
                cin>>e3;
                if(e1 && e2 && e3)
                {
                    add(dire,"WebKit");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for WEBKIT at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 5:
            {
                 int f1,f2,f3;
                cout<<"Do you have interest in cyber security? (YES - 1 and NO - 0)"<<endl;
                cin>>f1;
                cout<<"Do you like hacking or see your future in this field? (YES - 1 and NO - 0)"<<endl;
                cin>>f2;
                cout<<"Are you willing to take on challenging tasks? (YES - 1 and NO - 0)"<<endl;
                cin>>f3;
                if(f1 && f2 && f3)
                {
                    add(dire,"CINS");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for CINS at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 7:
            {
                int g1,g2,g3;
                cout<<"Do you have interest in interesting designs? (YES - 1 and NO - 0)"<<endl;
                cin>>g1;
                cout<<"Do you like to flaunt your imaginations through sketch? (YES - 1 and NO - 0)"<<endl;
                cin>>g2;
                cout<<"Are you willing to join Muse Club? (YES - 1 and NO - 0)"<<endl;
                cin>>g3;
                if(g1 && g2 && g3)
                {
                    add(dire,"Muse");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Muse at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 8:
            {
                int h1,h2,h3;
                cout<<"Do you have interest in public speaking? (YES - 1 and NO - 0)"<<endl;
                cin>>h1;
                cout<<"Do you like to prove your point through strong voice and facts? (YES - 1 and NO - 0)"<<endl;
                cin>>h2;
                cout<<"Do you want to learn how to convince others? (YES - 1 and NO - 0)"<<endl;
                cin>>h3;
                if(h1 && h2 && h3)
                {
                    add(dire,"Debate");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Debate Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 9:
            {
                int i1,i2,i3;
                cout<<"Do you have interest in music and musical instruments? (YES - 1 and NO - 0)"<<endl;
                cin>>i1;
                cout<<"Do you know how to play any musical instrument? (YES - 1 and NO - 0)"<<endl;
                cin>>i2;
                cout<<"Do you want to be a part of musical events and contests? (YES - 1 and NO - 0)"<<endl;
                cin>>i3;
                if(i1 && i2 && i3)
                {
                    add(dire,"Music");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Music Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
             case 10:
            {
                int j1,j2,j3;
                cout<<"Do you have interest in development? (YES - 1 and NO - 0)"<<endl;
                cin>>j1;
                cout<<"Do you know any languages like CSS? (YES - 1 and NO - 0)"<<endl;
                cin>>j2;
                cout<<"Do you want to be a part of Web development contests? (YES - 1 and NO - 0)"<<endl;
                cin>>j3;
                if(j1 && j2 && j3)
                {
                    add(dire,"Developer_Student");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Developer Student Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 11:
            {
                int k1,k2,k3;
                cout<<"Do you have interest in chess? (YES - 1 and NO - 0)"<<endl;
                cin>>k1;
                cout<<"Do you know all rules of chess=? (YES - 1 and NO - 0)"<<endl;
                cin>>k2;
                cout<<"Do you want to be a part of chess contests? (YES - 1 and NO - 0)"<<endl;
                cin>>k3;
                if(k1 && k2 && k3)
                {
                    add(dire,"Chess");
                }
                else
                {
                    cout<<<RED<"Sorry you are not eligible for Chess Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 12:
            {
                int l1,l2,l3;
                cout<<"Do you have interest in journalism and press reporting? (YES - 1 and NO - 0)"<<endl;
                cin>>l1;
                cout<<"Do you like to have your own views on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>l2;
                cout<<"Do you want to make a change through reporting and raising voice? (YES - 1 and NO - 0)"<<endl;
                cin>>l3;
                if(l1 && l2 && l3)
                {
                    add(dire,"Press");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Press Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 13:
            {
                int l1,l2,l3;
                cout<<"Do you like electronics? (YES - 1 and NO - 0)"<<endl;
                cin>>l1;
                cout<<"Have you made any hardware based projects? (YES - 1 and NO - 0)"<<endl;
                cin>>l2;
                cout<<"Do you want to be a part of workshops of electronics and Arduino? (YES - 1 and NO - 0)"<<endl;
                cin>>l3;
                if(l1 && l2 && l3)
                {
                    add(dire,"IEEE");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for IEEE at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 14:
            {
                int m1,m2,m3;
                cout<<"Do you like films? (YES - 1 and NO - 0)"<<endl;
                cin>>m1;
                cout<<"Have you ever recommended films to anyone? (YES - 1 and NO - 0)"<<endl;
                cin>>m2;
                cout<<"Do you want to organise movie nights for your friends? (YES - 1 and NO - 0)"<<endl;
                cin>>m3;
                if(m1 && m2 && m3)
                {
                    add(dire,"Film");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for film club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 15:
            {
                 int n1,n2,n3;
                cout<<"Do you like to do detail research on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>n1;
                cout<<"Do you like to personally rechack facts and figure to draw conclusions? (YES - 1 and NO - 0)"<<endl;
                cin>>n2;
                cout<<"Have you made any research based projects earlier also? (YES - 1 and NO - 0)"<<endl;
                cin>>n3;
                if(n1 && n2 && n3)
                {
                    add(dire,"Research");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for research club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 16:
            {
                int n1,n2,n3;
                cout<<"Do you like to apply deep logic to make program on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>n1;
                cout<<"Do you like competitive coding? (YES - 1 and NO - 0)"<<endl;
                cin>>n2;
                cout<<"Do you want to make career in coding? (YES - 1 and NO - 0)"<<endl;
                cin>>n3;
                if(n1 && n2 && n3)
                {
                    add(dire,"Programming");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for programming club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 17:
            {
                int o1,o2,o3;
                cout<<"Do you like taking photographs and videos? (YES - 1 and NO - 0)"<<endl;
                cin>>o1;
                cout<<"Do you like to take snapshots of beautiful landscapes? (YES - 1 and NO - 0)"<<endl;
                cin>>o2;
                cout<<"Are you interested in making detailed documentaries and editing videos? (YES - 1 and NO - 0)"<<endl;
                cin>>o3;
                if(o1 && o2 || o3)
                {
                    add(dire,"PMMC");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for PMMC at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 18:
            {
                int p1,p2,p3;
                cout<<"Do you enjoy while doing Garba? (YES - 1 and NO - 0)"<<endl;
                cin>>p1;
                cout<<"Are you excited to learn Garba? (YES - 1 and NO - 0)"<<endl;
                cin>>p2;
                cout<<"Do you play Garba on every occasion ? (YES - 1 and NO - 0)"<<endl;
                cin>>p3;
                if(p1 && p2 || p3)
                {
                    add(dire,"Khelaiya");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Khelaiya at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 19:
            {
                int q1,q2,q3;
                cout<<"Do you know how to solve a 3 x 3 Cube? (YES - 1 and NO - 0)"<<endl;
                cin>>q1;
                cout<<"Are you excited to learn 4 x 4 and 2 x 2 cube? (YES - 1 and NO - 0)"<<endl;
                cin>>q2;
                cout<<"Do you think you can represent DAIICT cubing club infront of other colleges ? (YES - 1 and NO - 0)"<<endl;
                cin>>q3;
                if(q1 && q2 && q3)
                {
                    add(dire,"Cubing");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Cubing Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 20:
            {
                int r1,r2,r3;
                cout<<"Do you want to create unforgettable memories? (YES - 1 and NO - 0)"<<endl;
                cin>>r1;
                cout<<"Do you want to organise trips ? (YES - 1 and NO - 0)"<<endl;
                cin>>r2;
                cout<<"Do you want to be part of excursion club? (YES - 1 and NO - 0)"<<endl;
                cin>>r3;
                if(r1 && r2 && r3)
                {
                    add(dire,"Excursion");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Excursion Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 21:
            {
                int r1,r2,r3;
                cout<<"Do you want to learn more about Bureau of Indian Standards? (YES - 1 and NO - 0)"<<endl;
                cin>>r1;
                cout<<"Do you want to be part of workshops and industrial visits ? (YES - 1 and NO - 0)"<<endl;
                cin>>r2;
                cout<<"Do you want to be part of BIS club? (YES - 1 and NO - 0)"<<endl;
                cin>>r3;
                if(r1 && r2 && r3)
                {
                    add(dire,"BIS");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for BIS Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 22:
            {
            int s1,s2,s3;
                cout<<"Do you want to rediscover architectural heritage of India? (YES - 1 and NO - 0)"<<endl;
                cin>>s1;
                cout<<"Do you want to unearth new facts and discover new things ? (YES - 1 and NO - 0)"<<endl;
                cin>>s2;
                cout<<"Do you want to uphold your heritage? (YES - 1 and NO - 0)"<<endl;
                cin>>s3;
                if(s1 && s2 && s3)
                {
                    add(dire,"Heritage");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Heritage Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 23:
            {
                int t1,t2,t3;
                cout<<"Do you want to play with Arduino, Nodemcu? (YES - 1 and NO - 0)"<<endl;
                cin>>t1;
                cout<<"Do you want to work on IoT projects ? (YES - 1 and NO - 0)"<<endl;
                cin>>t2;
                cout<<"Do you want to make hardware and electronics based projects? (YES - 1 and NO - 0)"<<endl;
                cin>>t3;
                if(t1 && t2 && t3)
                {
                    add(dire,"EHC");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Electronics Hobby Centre at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 24:
            {
                int u1,u2,u3;
                cout<<"Do you love quizes? (YES - 1 and NO - 0)"<<endl;
                cin>>u1;
                cout<<"Do you like to grasp new topics through intense quizes? (YES - 1 and NO - 0)"<<endl;
                cin>>u2;
                cout<<"Do you want to conduct intense quiz? (YES - 1 and NO - 0)"<<endl;
                cin>>u3;
                if(u1 && u2 && u3)
                {
                    add(dire,"Headrush_Quizzing");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for Headrush Quizzing Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case 25:
            {
                int v1,v2,v3;
                cout<<"Do you love plays? (YES - 1 and NO - 0)"<<endl;
                cin>>v1;
                cout<<"Do you like acting and playing different roles ? (YES - 1 and NO - 0)"<<endl;
                cin>>v2;
                cout<<"Do you like to express yourself through unique dialogue delivery? (YES - 1 and NO - 0)"<<endl;
                cin>>v3;
                if(v1 && v2 && v3)
                {
                    add(dire,"DAIICT_Theatre");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for DAIICT Theatre Group at DAIICT"<<RESET<<endl;
                }
                break;
            }
            case  26:
            {
                int v1,v2,v3;
                cout<<"Do you like playing with AI through different prompts? (YES - 1 and NO - 0)"<<endl;
                cin>>v1;
                cout<<"Do you like to generate crazy stuff ? (YES - 1 and NO - 0)"<<endl;
                cin>>v2;
                cout<<"Do you like to learn science behind AI? (YES - 1 and NO - 0)"<<endl;
                cin>>v3;
                if(v1 && v2 && v3)
                {
                    add(dire,"AI");
                }
                else
                {
                    cout<<RED<<"Sorry you are not eligible for AI Club at DAIICT"<<RESET<<endl;
                }
                break;
            }
            cout<<"If you want to continue, Press 1 or to exit Press 0"<<endl;
            cin>>c2;
        }
        
        }
        while(c2==1);

    
}

//-------------------------------------------------------------------------------------EVENTS----

#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

string club[] = {"AI", "Dance", "Research", "Chess", "Cubing", "Excursion", "Microsoft", "Radio", "DCEI", "Sambhav",
                 "Developer_Student", "WebKit", "Business", "BIS", "Debate", "Music", "Programming", "IEEE", "Heritage", "Headrush_Quizzing",
                 "Muse", "Press", "DAIICT_Theatre", "Film", "Khelaiya", "EHC", "PMMC", "CINS"};

class Event
{

public:

    string name;
    string date;
    string time;
    int rating;
    string venue;
    string in1;
    string in2;
    string rule1;
    string rule2;
    string rule3;

};

unordered_map<string, unordered_multimap<int,Event>> ev_load()
{

unordered_map<string, unordered_multimap<int,Event>> data;
    
data["Radio"].insert({4,{"Weekly Poetry Writing Challenge","07/04/2024","19:00 to 21:00",5,"Radio Room(CEP)",
"Every Year, the world celebrates the art of poetry writing in April, since 1996 and so it is called National Poetry Writing Month.",
"We invite all poets to share their unique perspectives through the poetry and share poem through recording or in written form",
"1. Poem should not intend anyone anyone's feelings or faith.",
"2. Avoid the use of vulgar language.","3. Please submit your creations before the submission date."}});

data["Radio"].insert({10,{"Ink Chronicles","20/1/2024","20:00 to 22:00",4,"Online",
"This contest is our exclusive event where you can pour your heart out in a letter to your favourite chracacter.",
"Show your creativity and express your admiration for the characters who left an indelible mark on your mind through an open letter to them.",
"1. Your letter should not intend anyone anyone's feelings or faith.","2. Avoid the use of vulgar language.",
"3. Please submit your creations before the submission date."}});

data["AI"].insert({11,{"iPrompt","05/11/2024","14:00 to 16:00",5,"CEP 110","In this event, creativity and technology converge in an extraordinary way.",
"In this challenge, you will be provided with images and prompts, and with power of AI, you will transform these prompts into AI artwork and show your AI creativity.",
"1. Your creativity should not intend anyone anyone's feelings or faith.",
"2. Please avoid any art which contains objectionable things","3. Please submit your work before 04/11/2024."}});

data["AI"].insert({8,{"Prompt-A-Thon","21/08/2024","19:00 to 21:00",5,"Online",
"AI Club is holding an event where you will send prompts based on wildest and out of box scenarios and you may also onvert it into AI framework.",
"Let the horse of imagination run. The most interesting prompts will be awarded.","1. Your creativity should not intend anyone anyone's feelings or faith.",
"2. Please avoid any art which contains objectionable things","3. Please submit your work before 20/08/2024."}});

data["Chess"].insert({11,{"Chess64","04/11/2024","12:00 to 14:00",5,"OAT","All the chess enthusiasts out there, get ready with your amazing strategies and cool tactics.",
"We all want you to participate in Chess64, where you can unleash your inner Grandmaster and show off your strategic brilliance.",
"1. Please do not cheat or indulge in any unfair practices.","2. The final decision is in hands of judges.",
"3. You will be given specific time limit and you cannot exceed that."}});

data["Chess"].insert({1,{"Rapid Chess Tournament","16/01/2024","21:00 to 23:00",4,
"CEP-106","This rapid tournament for all the chess experts and enthusiasts out there. You can bring your A game to the table.",
"Everyone will be suggested to install the chess clock application on your mobile.",
"1. Please do not cheat or indulge in any unfair practices.","2. The final decision is in hands of judges.",
"3. You will be given specific time limit and you cannot exceed that."}});

data["Music"].insert({2,{"RAAGA AND RHAPSODY","24/02/2024","16:00 to 18:00",4,"OAT",
"We are thrilled to extend an invitation to you for our prestigious singing competition, RAAGA AND RHAPSODY as part of Synapse. Whether you're a solo performer, a dynamic duet, or a harmonious group, this event promises to showcase your vocal talents",
"Join us in celebrating music's magic and make your mark in this unforgettable experience.",
"1. You should report 30 mins prior to thee event.","2. Time Limit for solo/duet category is 5-7 mins and for team, it is 8-10 mins.",
"3. Team can be of maximum 4 members"}});

data["PMMC"].insert({2,{"Festive Frames Photography Contest","22/02/2024","10:00 to 18:00",4,"Online",
"We're thrilled to announce a captivating opportunity for all the shutterbugs and photography enthusiasts out there! PMMC is organizing a brand new contest titled Festive Frames",
"The theme of this exciting contest revolves around capturing the vibrant essence of our college fest through your lens",
"1. Photoshopped, heavily edited entries will be rejected.","2. Multiple entries are not allowed.", 
"3. Your submission should include your Name, contact number."}});

data["PMMC"].insert({12,{"Rolling Shutter(Videography)","17/12/2024","1 month",3,"Online",
"We are thrilled to invite you to participate in Rolling Shutter, our month-long videography challenge tailored for storytellers and visionaries. This challenge aims to showcase your creativity in narrating compelling visual tales through the lens of your camera.",
"Capture the essence of your entire break, showcasing the variety of activities and experiences that define your vacation.",
"1.Time limit: Entries should be of length between 60 Sec and 3 Minutes. Maximum Team size: 3",
"2. Entries can be submitted by individuals or by teams of a maximum size", 
"3. The deadline to submit your entry is 17th January 11:59 PM."}});
    
data["Khelaiya"].insert({9,{"Garba Night","14/09/2024","21:00 to 22:45",5,"OAT",
"The time for a lively Garba Night has arrived! It's an opportunity for all of us to come together and enjoy a night filled with dance, music, and fun.",
"From the splendid beauty of Ras Garba to energetic Dakla, from Titodo to Timli, from Sanedo to Bhai Bhai - it's time to celebrate and enjoy the night at its fullest.",
"1. Please wear traditional clothes.","2. Please arrive on time.","3. Please maintain decorum and cleanliness."}});

data["Khelaiya"].insert({9,{"Sheri Garba","15/09/2024","22:00 to 23:00",5,"SAC Ground",
"We are excited to invite you to a night filled with joy, music, and dance as we kick off the Garba night with Sheri Garba.",
"Get set to dance the night away at our Sheri Garba event! We're bringing the lively sounds of traditional dhol and sharnai to make the evening unforgettable!",
"1. Please wear traditional clothes.","2. Please arrive on time.","3. Please maintain decorum and cleanliness."}});

data["Film"].insert({3,{"IPL Screening","31/03/2024","19:00 to 23:00",5,"LT2",
"Join us for an evening filled with the electrifying atmosphere of cricket as we gather together to witness the battle between two formidable teams.",
"Whether you're a die-hard fan or just looking for a fun night of cricket, this event promises to be a memorable one.",
"1. Please arrive on time to enjoy to the fullest.",
"2. Please maintain the infrastructure of LT and do not break anything","3. Please maintain decorum and peace."}});

data["Film"].insert({1,{"Movie Screening","10/01/2024","21:00 to 23:59",5,"LT2",
"Get ready for a night of cinematic brilliance because this week, we're bringing you the unforgettable Inglourious Basterds! It's time to take a break from the daily grind and immerse yourself in Tarantino's world of action, humor, and pure adrenaline.",
"We will hosts more such movie nights.","1. Please arrive on time to enjoy to the fullest.","2. Please maintain the infrastructure of LT and do not break anything",
"3. Please maintain decorum and peace."}});

data["Press"].insert({10,{"Comic Carnival: A Comic Making Challenge","17/10/2024","Whole day",5,"Online","This is an opportunity to bring your imagination to life through comics.",
"A picture speaks a thousand words, and likewise, a great comic strip can contain stories that would otherwise span paragraphs. So if you can depict a relatable anecdote in a humorous manner or rather something touching, send us your entries!",
"1. You have to form a team of two members.", "2. Your comic strip can span multiple panels or it could be a single panel as well.",
"3. There is a maximum page limit of 6, but no cap on the number of panels."}});

data["Press"].insert({2,{"Valentine's Poetry Contest","13/02/2024","Whole Day",4,"Online",
"As you might be aware, Valentine's week is going on. And we hope you have a better half to share roses, chocolates and gifts with. Those who don't, no worries, your Valentine can be anyone you truly love (your parents).",
"To celebrate this occasion, what better medium of expression can there be to convey your boundless love to your beloved than poetry.",
"1. Entries can be in 3 languages: English, Hindi, Gujarati","2. Submissions after deadline won't be accepted.","3. One entry per person is allowed."}});

data["Research"].insert({11,{"i.Papyrus","04/11/2024","17:00 to 19:00",5,"CEP-110",
"Research Club DAIICT, in association with i.Fest, invites you all to participate in our annual poster presentation competition, i.Papyrus!!",
"Winners would be rewarded with prizes from the pool of 3.5k+!! So channel your inner researcher and participate in this amazing competition.",
"1. Each team can only submit a single poster.","2. The allowed team size is 1-3.",
"3. Each team must have all members unique and no other team sharing a common member, failure to do so will immediately disqualify the team(s)"}});

data["Cubing"].insert({2,{"SYNOCUBIX","24/02/2024","17:00 to 19:00",4,"LT-3","It is a great event which is part of official WCA i.cube.",
"Cubers will have the chance to flaunt their cubing skills in front of everyone and will strive to make the most of theirskill.",
 "1. One person can register only once.","2. You need not bring your own cube.","3. Please check your email ID while registering."}});

data["Cubing"].insert({1,{"Mosaic Construction: Republic Day","24/01/2024","10:00 to 12:00",5,"SAC Foyer",
"As we approach the Republic Day of India, we are delighted to invite you to participate in crafting a Rubik's Cube mosaic, serving as a symbol of our collective unity, diversity, and the indomitable spirit of innovation.",
"No prior experience with Rubik's Cubes is necessary; all skill levels are welcome! We will provide guidance and assistance throughout the event.",
"1. Please come on time.","2. Please maintain decorum throughout the whole event","3. You need not bring your own cube."}});

//Excursion club has no events
data["DCEI"].insert({11,{"SellOut","04/11/2024","16:00 to 18:00",5,"LT1"," SellOut that is open for everyone willing to show their creativity, entrepreneurial skills, and imagination.",
" The event being a fun event also gives glimpses of how real-world dealings happen.","1. One participant can only register once.",
"2. You must have the registration for the ifest.","3. Evaluation will be done on the basis of the answers given. Evaluation will be done by team DCEI."}});

data["Sambhav"].insert({4,{"Blood Donation Camp","05/04/2024","14:00 to 17:00",4,"Faculty Mess(Near K++)",
"We are pleased to announce that we are organizing a Blood Donation Camp in association with the Indian Red Cross Society.",
"Even the slightest bit of help is welcome and greatly appreciated. ","1.  You are advised to follow the COVID protocols.",
"2. Please get a basic medical checkup done.","3. Please inform the doctor if you are suffering from any disease."}});

data["Developer_Student"].insert({1,{"India Regional Bootcamp","21/01/2024","Unknown",5,"Online","This is your opportunity to solve real world problems, help users in real time and get recognised for the same!",
"The India Regional Bootcamp is cherry on the cake, to elevate your projects and get guidance from industry experts",
"1. Only one team member per team is allowed to join the regional bootcamp.","2. In case you are not shortlisted, we will not be able to share the exact reasons.",
"3. GDSC India Team reserves the right to invite, shortlist and confirm your participation for the same. The shortlisting criteria is subjected to various factors and will not be disclosed."}});

data["Developer_Student"].insert({1,{"GoLang Session","16/01/2024","21:00 to 23:00",5,"CEP 106",
"We are excited to invite you to our upcoming GoLang session at GDSC, where we will delve into the world of Go programming language and its applications.",
"Whether you are a seasoned developer or just curious about new technologies, this session is tailored for everyone interested in exploring the capabilities of GoLang.",
"1. Bring your laptops","2. Please register before coming.","3. Please maintain the decorum."}});

//WebKit club, no events found
data["Business"].insert({2,{"echai","16/02/2024","18:30 to 20:00",5,"LT1",
" eChai 2.0 is a dynamic and enriching networking event tailored to ignite your entrepreneurial spirit and foster innovation right here at DA-IICT!",
"eChai 2.0 promises to be an engaging platform where you can interact with accomplished entrepreneurs, exchange ideas, and explore new strategies to fuel your entrepreneurial journey.",
"1. Please register for this event.","2. Please maintain respect for the speaker.",
"3. Please maintain cleanliness in the hall."}});

data["BIS"].insert({2,{"Shaping Tomorrow's Sustainability Standards","15/02/2024","Whole day",5,"Online",
"The Bureau of Indian Standards (BIS) has launched the Shaping Tomorrow's Sustainability Standards contest.",
"This contest aims to inspire students and research scholars to identify new areas where standards can be developed to address sustainability and climate change issues.",
"1. You can only submit one entry at a time.","2. Submit your entry before the deadline.",
"3. Please attach a copy of Valid Student ID card with your entry"}});

data["BIS"].insert({3,{"Online Lecture Series","04/03/2024","16:00 to 17:30",5,"Webex(Online)","You are invited to the BIS Online Lecture Series Let's Talk about Standards: Electronics and IT",
"BIS is starting an interactive online lecture series titled 'Let's Talk about Standards' to take the initiative of Education Outreach forward with all the our eminent MoU partner Institutes",
"1. Please turn off your mic during the session unless told.","2. Switch on your camera during the whole session.","3. Email any doubts if you have."}});

data["Debate"].insert({2,{"Shipwreck and Prized British Parliamentary Debate!","15/02/2024","20:45 to 22:15",5,"CEP 106",
"Prepare to dive into the depths of discussion as Shipwreck offers a unique twist on traditional debate formats.",
"Engage in stimulating discourse on various intriguing topics, navigating through the waves of argumentation and wit.",
"1. You shall not hurt anybody's feelings intentionally","2. The langauge used shall be respectable.",
"3. Please don't harm any infrastructure."}});

data["Programming"].insert({3,{"Holi Long Programming Contest","For 7 Days","15:00 to 19:00",5,"Online",
"This is an exciting opportunity for all coding enthusiasts to come together and test their skills in a fun and challenging environment.", 
"Starting on 25th March, this contest will span over 7 days, featuring a new question each day, gradually building up the excitement and challenge.",
"1. On the first day, it will have 4 questions and for the next 6 days, we will have 1 question coming up at 3:00 pm exactly",
"2. There are prizes for the first solver.",
"3. You can submit one question only once."}});

data["Programming"].insert({2,{"IPC","01/02/2024","21:00 to 23:00",5,"Online",
"The Programming Club is here with the 5th IPC of the academic year.",
"Seize this opportunity to showcase your programming skills and improve your capabilities.",
"1. It is forbidden to use somebody else's code in the solution.",
"2. It is allowed to use any sources of information on the Internet (but it is forbidden to copy-paste somebody else's code).",
"3. The programming Club has the right to monitor the contestants' honesty in behavior using different methods and disqualify the contestant if violations are found."}});

data["Microsoft"].insert({3,{"Face Off 4.0","11/03/2024","15:00 to 18:00",5,"Online",
"MSTC is back again with a blast. We are thrilled to officially announce the upcoming Face Off 4.0, a highly anticipated 1v1 Competitive Programming.",
" If you are someone who has been delving into the deep worlds of Competitive Programming and DSA, this is something you don't want to miss.",
"1. You will have to register in your applied category.","2. You will have to register on the codeforces before the contest.",
"3. Each category will witness 5 competitive rounds with the first round being open to all for the participant of respective categories from which 32 top participants will be selected to compete in a 1v1 format."}});

data["Microsoft"].insert({12,{"Winter Of Code","30/12/2024","1 month",5,"Online",
" As the winter chill sets in, we are thrilled to announce the opening of registrations for the highly anticipated Winter of Code", 
"It is a month-long program where you will get a chance to learn a new tech-stack from scratch without spending a single penny.",
"1.It is forbidden to use somebody else's code in the solution.",
"2.You may use third-party prewritten code, like the template of some algorithms.",
"But you are not allowed to use the whole code with the logic of others."}});

data["Heritage"].insert({11,{"Rangoli Competition: Unleash Your Creativity!","6/11/2024","18:30 to 19:30",5,"OAT",
"The Heritage Club is thrilled to announce an upcoming Rangoli Competition", 
"This competition promises to be an exciting event where your creativity can shine.",
"1.Form a team of 3-6 individuals to participate.","2.Only include 1 kg of white color and 500g each of six vibrant colors.",
"3. Do not spoil others art."}});

data["Headrush_Quizzing"].insert({11,{"i.Quiz","05/11/2024","9:00 to 10:30",5,"CEP-110",
"Headrush in association with i.Fest is organizing a science and technology quiz, i.Quiz, where your knowledge in the domains of physics, chemistry, biology and information technology will be put to a test.",
"It will be exciting.",
"1. Do not use internet.","2. Maintain decorum in the hall","3.Don't forget to bring a sheet of paper and a pen."}});

data["Dance"].insert({3,{"WALTZ","12/03/2024","21:00 to 22:30",4,"OAT",
"This event promises to be an electrifying celebration of dance, talent, and creativity.",
"We cordially invite you all to participate and showcase your skills on the dance floor.",
"1. Only one member per team is required to fill out the form for team registration.",
"2. On-the-spot registrations won't be entertained.","3. Any kind of obscenity will not be entertained under any circumstances."}});

data["IEEE"].insert({2,{"Public Speaking Workshop","17/02/2024","16:00 to 19:00",5,"CEP-110",
"We cordially invite you to participate in the Public Speaking Workshop organized by the IEEE Student Branch DAIICT.",
"This workshop aims to equip participants with essential public speaking skills crucial for various aspects of personal and professional life.",
"1. There is no fees.","2. Please arrive in the workshop on time.","3. Please email if you have any doubts."}});

data["IEEE"].insert({3,{"DA-IICT MUN","10/03/2024","16:00 to 21:00",5,"LT2",
"IEEE SB DAIICT along with DebSoc DA-IICT and the expertise of the Turning Point community brings to you, DA-IICT MUN.",
"“Model United Nations” or MUN is an educational simulation in which students learn about diplomacy, and international relations and get a chance to experience and understand the workings of the United Nations.",
"1. ₹1000 per delegate for non-IEEE members","2.₹800 for IEEE members",
"3. You need to attend the pre-MUN Training Workshop."}});

data["EHC"].insert({10,{"EHC Session on Arduino","06/10/2024","18:30 to 19:45",5,"LT2",
"The Electronics Hobby Center is dedicated to fostering a passion for electronics, providing hands-on experience, and creating a supportive community for all those interested in the field.",
"Join us for an exciting Arduino session tailored for beginners!",
"1. Please join us on time.","2. You may ask questions if you have doubt by raising hands.","3. You need to regisster first."}});

data["CINS"].insert({2,{"Cyber Samvad","24/02/2024","10:00 to 11:00",3,"LT1",
"Given the rising instances of cybercrimes, understanding the fundamentals of staying safe online has become paramount.", 
"With this in mind, the CINS club is excited to announce the  Cyber Samvad.",
"1. You need to register before joining the event.","2. Please arrive on time.",
"3. Following the discussion, there will be a Q&A session where the audience can have their queries addressed"}});

data["DAIICT_Theatre"].insert({4,{"Krishna Leela Auditions","02/04/2024","21:00 to 22:45",4,"LT1",
"DTG is all set to bring back one of the biggest celebrations of DAIICT. Krishna Leela is happening and we will leave no stone unturned to give you an experience of a lifetime.",
"As we start preparing, we will be taking auditions for all roles for Krishna Leela once again.",
"1. You can participate only as an actor or writer.","2. Auditions are compulsory to take part in Leela",
"3. For any queries, you can revert to us"}});

data["DAIICT_Theatre"].insert({1,{"Rangmanch - The Drama Night","01/01/2024","21:00 to 23:45",4,"OAT",
"We have three main categories for the event - Stage Play, Felicity and Mono Act.",
" Put on your thinking caps, jot down a tale that mesmerizes the audience and captivates every mind!",
"1. Anyone can develop one's own script and send their team details.",
"2.To contact DTG, drop a mail at theatres@daiict.ac.in.",
"3. The deadline for submitting the Entry form is extended to 10th Jan 2024"}});

data["Muse"].insert({4,{"Museliversary","04/04/2024","17:00 to 19:00",5,"Cafeteria",
"To mark this special anniversary, we prepare an array of exciting activities every year on this day.",
"We're celebrating three years of creativity, innovation, and unforgettable moments that have brought us together as a community.",
"1. Please maintain the decorum while celebrating",
"2. Please arrive on time.",
"3. Please maintain cleanliness in the cafeteria."}});

return data;
}

void event(unordered_map<string, unordered_multimap<int, Event>> &data)
{
    std::cout <<BLUE<< "1.to get info of any particular event" <<RESET<< endl;
    std::cout <<BLUE<< "2.to get info of all events of an club " <<RESET<< endl;
    std::cout <<BLUE<< "3.to get info of all events in a particular month " <<RESET<< endl;
    std::cout <<BLUE<< "4.to get info of all events of an club in a particular month " <<RESET<< endl;
    std::cout <<BLUE<< "5.if you don't know how many events conducted by clubs of daiict You will get info of all events" <<RESET<< endl;
    std::cout << "Enter Choice: ";
    int n;
    std::cin >> n;
    std::cin.ignore();
    switch (n)
    {
    case 1:
    {
    it:
        cout << "Enter Event name: ";
        string evna;
        std::getline(cin, evna)<< 
        int a = 0;
        for (int i = 0; i < 28; ++i)
        {
            for (auto eve : data[club[i]]<< 
            {
                if (eve.second.name == evna)
                {
                    std::cout << endl;
                    std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
                    std::cout <<BOLD_GREEN<< "Event Detials: " <<RESET<< endl;
                    std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
                    std::cout <<CYAN<< left << setw(10) << "Club Name" << ": " << club[i] <<RESET<< endl;
                    std::cout <<CYAN< left << setw(10) << "Name" << ": " << eve.second.name <<RESET<< endl;
                    std::cout <<CYAN<< left << setw(10) << "Date" << ": " << eve.second.date <<RESET<< endl;
                    std::cout <<CYAN<< left << setw(10) << "Time" << ": " << eve.second.time <<RESET<< endl;
                    std::cout <<<CYAN< left << setw(10) << "Venue" << ": " << eve.second.venue <<RESET<< endl;
                    std::cout <<CYAN<< left << setw(10) << "Rating" << ": " << eve.second.rating <<RESET<< endl;
                    std::cout << "------------------------------" << endl;
                    std::cout << left << setw(12) << "Information" << ": " << eve.second.in1 << endl;
                    std::cout << "              " << eve.second.in2 << endl;
                    std::cout << endl;
                    std::cout << left << setw(12) << "Rules" << ": " << eve.second.rule1 << endl;
                    std::cout << "              " << eve.second.rule2 << endl;
                    std::cout << "              " << eve.second.rule3 << endl;
                    std::cout << "------------------------------" << endl;
                    std::cout << endl<< 
                    a = 1;
                    break;
                }
            }
        }

        if (a == 0)
        {
            std::cout << "You provided wrong event name" << endl;
            std::cout << "Press 1 to enter name again or 0 to leave: ";
            int n;
            std::cin >> n;
            cin.ignore();
            if (n == 1)
            {
                goto it;
            }
        }
        break;
    }
    case 2:
    {
    it1:
        string cl;
        std::cout << "Enter the name of the club: ";
        std::getline(cin, cl);
        int a = 0;
        if(!data[cl].empty()){
        for (auto eve : data[cl])
        {
            if(a==0){
            std::cout << endl;
            std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
            std::cout <<BOLD_GREEN<< "Event Detials: " <<RESET<< endl;
            }
            std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Club Name" << ": " << cl <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Name" << ": " << eve.second.name <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Date" << ": " << eve.second.date <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Time" << ": " << eve.second.time <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Venue" << ": " << eve.second.venue <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Rating" << ": " << eve.second.rating <<RESET<< endl;
            std::cout << "------------------------------" << endl;
            std::cout << left << setw(12) << "Information" << ": " << eve.second.in1 << endl;
            std::cout << "              " << eve.second.in2 << endl;
            std::cout << "------------------------------" << endl;
            std::cout << endl;
            a++;
        }}
        else
        {
            std::cout << "You provided wrong club name" << endl;
            std::cout << "Press 1 to enter name again or 0 to leave: ";
            int n;
            std::cin >> n;
            cin.ignore();

            if (n == 1)
            {
                goto it1;
            }
        }
        break;
    }
    case 3:
    {
    it2:
        int mn;
        std::cout << "Enter number of month(in integer): ";
        std::cin >> mn;
        int a = 0;
        for (int i = 0; i < 28; ++i)
        {
            auto temp = data[club[i]].equal_range(mn);

            for (auto person = temp.first; person != temp.second; ++person)
            {
                if(a==0){
                std::cout << endl;
                std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
                std::cout <<BOLD_GREEN<< "Event Details: " <<RESET<< endl;
                }
                std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Club Name" << ": " << club[i] <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Name" << ": " << person->second.name <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Date" << ": " << person->second.date <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Time" << ": " << person->second.time <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Venue" << ": " << person->second.venue <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Rating" << ": " << person->second.rating <<RESET<< endl;
                std::cout << "------------------------------" << endl;
                std::cout << left << setw(12) << "Information" << ": " << person->second.in1 << endl;
                std::cout << "              " << person->second.in2 << endl;
                std::cout << "------------------------------" << endl;
                std::cout << endl;
                a++;
            }
        }
        if (a == 0)
        {
            std::cout <<RED<< "Sorry there is no event in this month" <<RESET<< endl;
            std::cout << "Press 1 to enter month again or 0 to leave: ";
            int n;
            std::cin >> n;
            cin.ignore();
            if (n == 1)
            {
                goto it2;
            }
        }
        break;
    }
    case 4:
    {
    it3:
        int mn;
        string cl;
        std::cout << "Enter name of the club and month: ";
        std::getline(cin, cl);
        cin >> mn;
        int a = 0;
        auto temp = data[cl].equal_range(mn);
        for (auto person = temp.first; person != temp.second; ++person)
        {
            if(a==0){
            std::cout << endl;
            std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
            std::cout <<BOLD_GREEN<< "Event Details: " <<RESET<< endl;
            }
            std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Club Name" << ": " << cl << endl;
            std::cout <<CYAN<< left << setw(10) << "Name" << ": " << person->second.name <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Date" << ": " << person->second.date <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Time" << ": " << person->second.time <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Venue" << ": " << person->second.venue <<RESET<< endl;
            std::cout <<CYAN<< left << setw(10) << "Rating" << ": " << person->second.rating <<RESET<< endl;
            std::cout << "------------------------------" << endl;
            std::cout << left << setw(12) << "Information" << ": " << person->second.in1 << endl;
            std::cout << "              " << person->second.in2 << endl;
            std::cout << "------------------------------" << endl;
            std::cout << endl;
            a++;
        }
        if (a == 0)
        {
            std::cout << "There is no event in this month for "<<cl<<" club" << endl;
            std::cout << "Press 1 to Enter name of the club and month again or 0 to leave: ";
            int n;
            std::cin >> n;
            cin.ignore();
            if (n == 1)
            {
                goto it3;
            }
        }
        break;
    }
    case 5:
    {
        std::cout << "Here is detail of all events" << endl;
        std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
        std::cout <<BOLD_GREEN<< "Event Detials: " <<RESET<< endl;
        
        for (int i = 0; i < 28; ++i)
        {
            for (auto eve : data[club[i]])
            {
                std::cout << endl;
                std::cout <<BOLD_BLUE<< "------------------------------" <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Club Name" << ": " << club[i] <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Name" << ": " << eve.second.name <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Date" << ": " << eve.second.date <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Time" << ": " << eve.second.time <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Venue" << ": " << eve.second.venue <<RESET<< endl;
                std::cout <<CYAN<< left << setw(10) << "Rating" << ": " << eve.second.rating <<RESET<< endl;
                std::cout << "------------------------------" << endl;
                std::cout << left << setw(12) << "Information" << ": " << eve.second.in1 << endl;
                std::cout << "              " << eve.second.in2 << endl;
                std::cout << endl;
                std::cout << left << setw(12) << "Rules" << ": " << eve.second.rule1 << endl;
                std::cout << "              " << eve.second.rule2 << endl;
                std::cout << "              " << eve.second.rule3 << endl;
                std::cout << "------------------------------" << endl;
                std::cout << endl;
            }
        }
        break;
    }
    }
}
void edit_ev(unordered_map<string, unordered_multimap<int, Event>> &data, unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory)
{
    std::cout << "Enter your id: ";
    long long id;
    string cl;
    cin >> id;
    std::cout << "Enter the name of the club name whose event you want to change: ";
    cin >> cl;
    cin.ignore();
    int b = 0;

    for (int i = 0; i < 28; ++i)
    {
        auto person = directory[cl].find(id);
        if (person != directory[cl].end())
        {
            if (person->second.second.second == "Core")
            {
                b = 1;
                break;
            }
        }
    }

    if (b == 0)
    {
        cout << endl;
        std::cout << "You are not a core member of " << cl << " club, so you can't edit its events" << endl;
    }
    else
    {
        cout << endl;
        int a = 0;
        std::cout << "You are a core member of " << cl << ", so you can make changes to its events" << endl;
        cout << endl;
        cout << "Here all events which are held by " << cl << endl;
        int i = 1;
        for (auto eve : data[cl])
        {
            std::cout << left << setw(2) << i << ": " << eve.second.name << endl;
            i++;
        }
        cout << endl;
        std::cout << "Enter the name of the event you want to edit: ";
        string evna;
        getline(cin, evna);
        for (int i = 0; i < 28; ++i)
        {
            for (auto &eve : data[cl])
            {
                if (eve.second.name == evna)
                {
                label:
                    cout << endl;
                    std::cout <<BOLD_BLUE<< "Enter the new details for the event " << evna <<RESET<< endl;
                    std::cout <<BOLD_BLUE<< "Which type of information you want to edit: " <<RESET<< endl
                              <<BRIGHT_MAGENTA<< "1.to Modify Date" <<RESET<< endl
                              <<BRIGHT_MAGENTA<< "2.to Modify Time" <<RESET<< endl
                              <<BRIGHT_MAGENTA<< "3.to Modify Venue" <<RESET<< endl
                              <<BRIGHT_MAGENTA<< "4.to Modify date time Venue" <<RESET<< endl
                              <<BRIGHT_MAGENTA<< "5.to exit" <<RESET<< endl;
                    std::cout << "Enter Choice: ";
                    int x;
                    cin >> x;
                    cin.ignore();
                    switch (x)
                    {
                    case 1:
                    {
                        cout << endl;
                        string newdata;
                        std::cout << "Date(dd/mm/yyyy): ";
                        getline(cin, newdata);
                        for (int j = 0; j < 28; ++j)
                        {
                            for (auto &other_eve : data[club[j]])
                            {
                                if (other_eve.second.name != eve.second.name &&
                                    other_eve.second.date == newdata &&
                                    other_eve.second.time == eve.second.time &&
                                    other_eve.second.venue == eve.second.venue)
                                {
                                    std::cout << "Another event is already scheduled at that time or date" << endl;
                                    std::cout << "Do you want to retry with different details? (y/n): ";
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y' || choice == 'Y')
                                    {
                                        goto label;
                                    }
                                    else
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                        if (newdata == eve.second.date)
                        {
                            cout << endl;
                            cout << "Enter new date which is different from Previous date..!!";
                            cout << endl;
                            goto label;
                        }
                        eve.second.date = newdata;
                        break;
                    }
                    case 2:
                    {
                        cout << endl;
                        string newdata;
                        std::cout << "Time: ";
                        getline(cin, newdata);
                        for (int j = 0; j < 28; ++j)
                        {
                            for (auto &other_eve : data[club[j]])
                            {
                                if (other_eve.second.name != eve.second.name &&
                                    other_eve.second.date == eve.second.date &&
                                    other_eve.second.time == newdata &&
                                    other_eve.second.venue == eve.second.venue)
                                {
                                    cout << endl;
                                    std::cout << "Another event is already scheduled at that time or date" << endl;
                                    std::cout << "Do you want to retry with different details? (y/n): ";
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y' || choice == 'Y')
                                    {
                                        goto label;
                                    }
                                    else
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                        if (newdata == eve.second.time)
                        {
                            cout << endl;
                            cout << "Enter new time which is different from Previous time..!!";
                            cout << endl;
                            goto label;
                        }
                        eve.second.time = newdata;
                        break;
                    }
                    case 3:
                    {
                        string newdata;
                        std::cout << "Venue: ";
                        getline(cin, newdata);
                        for (int j = 0; j < 28; ++j)
                        {
                            for (auto &other_eve : data[club[j]])
                            {
                                cout << endl;
                                if (other_eve.second.name != eve.second.name &&
                                    other_eve.second.date == eve.second.date &&
                                    other_eve.second.time == eve.second.time &&
                                    other_eve.second.venue == newdata)
                                {
                                    cout << endl;
                                    std::cout << "Another event is already scheduled at that time or date" << endl;
                                    std::cout << "Do you want to retry with different details? (y/n): ";
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y' || choice == 'Y')
                                    {
                                        goto label;
                                    }
                                    else
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                        if (newdata == eve.second.venue)
                        {
                            cout << endl;
                            cout << "Enter new venue which is different from Previous venue..!!";
                            cout << endl;
                            goto label;
                        }
                        eve.second.venue = newdata;
                        break;
                    }
                    case 4:
                    {
                        string newdata1, newdata2, newdata3;
                        std::cout << "Date(dd/mm/yyyy): ";
                        getline(cin, newdata1);
                        std::cout << "Time: ";
                        getline(cin, newdata2);
                        std::cout << "Venue: ";
                        getline(cin, newdata3);
                        for (int j = 0; j < 28; ++j)
                        {
                            for (auto &other_eve : data[club[j]])
                            {
                                cout << endl;
                                if (other_eve.second.name != eve.second.name &&
                                    other_eve.second.date == newdata1 &&
                                    other_eve.second.time == newdata2 &&
                                    other_eve.second.venue == newdata3)
                                {
                                    std::cout << "Another event is already scheduled at that time or date" << endl;
                                    std::cout << "Do you want to retry with different details? (y/n): ";
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y' || choice == 'Y')
                                    {
                                        goto label;
                                    }
                                    else
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                        if (newdata1 == eve.second.date && newdata2 == eve.second.time && newdata3 == eve.second.venue)
                        {
                            cout << endl;
                            cout << "Enter new data which is different from Previous date..!!";
                            cout << endl;
                            goto label;
                        }
                        eve.second.date = newdata1;
                        eve.second.time = newdata2;
                        eve.second.venue = newdata3;
                        break;
                    }
                    case 5:
                    {
                        return;
                    }
                    }
                    std::cout << "Event " << evna << " has been updated" << endl;
                    a = 1;
                    break;
                }
            }
            if (a == 1)
                break;
        }
        if (a == 0)
        {
            cout << endl;
            std::cout << "Event " << evna << " not found" << endl;
        }
    }
}
//--------------------------------------------------------------
unordered_map<string,unordered_map<string,Person>> par_load(string file_name){

    unordered_map<string,unordered_map<string,Person>> detail;

    ifstream fin;

    fin.open(file_name,ios :: in);

    Person A;
    string temp,event,username;

    while(fin>>A.name>>temp>>A.contact>>A.emid>>username>>A.password){
        getline(fin,event);
        event.erase(0,1);
        A.name = A.name +" " + temp;
        
        detail[event][username] = A;
    }

    fin.close();

    return detail;

}

void ev_par(unordered_map<string, unordered_map<string, Person>> &data, unordered_map<string, unordered_multimap<int, Event>> &info, string file_name)
{

    char temp;
    cout << "Have you registered yourself ?? (Enter Y/N): ";
    cin >> temp;
    cout << endl;
    cin.ignore();

    Person A;
    string uname, tem, evname;

    if (temp == 'N')
    {

        cout << "You are new candidate please register yourself" << endl;
        cout << "----------------------------------------------" << endl;
        cout << setw(20) << "Please enter your name : ";
        getline(cin, A.name);
        cout << setw(20) << "Enter your contact number: ";
        cin >> A.contact;
        cout << setw(20) << "Enter your email id: ";
        cin >> A.emid;
    la:
        cout << setw(20) << "Now create your user name: ";
        cin >> uname;

        for (const auto& event : data) {
            const auto& participants = event.second;
            auto person = participants.find(uname);
            if (person != participants.end()) {
                cout <<RED<< "This username already exists in event: " << event.first <<RESET<< endl;
                cout <<RED<< "Please enter a new username" <<RESET<< endl;
                goto la;
            }
        }

    la1:
        cout << setw(20) << "Now create password: ";
        cin >> A.password;
        cout << setw(20) << "Please enter your password again:";
        cin >> tem;
        cout << endl;

        if (tem != A.password)
        {
            cout <<YELLOW<< "Both password are not matching!, Please make your password again" <<RESET<< endl;
            cout << endl;
            goto la1;
        }

        cout <<GREEN<< "You are registration completed sucessfully" <<RESET<< endl;
    }
    else
    {
    la3:
        int a = 0;
        cout << setw(20) << "Enter your username: ";
        cin >> uname;
        cout << setw(20) << "Now enter your password: ";
        cin >> A.password;
        cout << endl;

        for (int i = 0; i < ev->size(); ++i)
        {
            auto person = data[ev[i]].find(uname);
            if (person != data[ev[i]].end())
            {
                if (person->second.password == A.password)
                {
                    a = 1;
                    A.contact = person->second.contact;
                    A.emid = person->second.emid;
                    A.name = person->second.name;
                    A.password = person->second.password;
                    break;
                }
            }
        }

        if (a == 0)
        {
            cout <<BRIGHT_RED<< "Incorrect user-name or password" <<RESET<< endl;
            int k;
            cout << "Press 1 to re-enter or 0 to exit: ";
            cin >> k;
            if (k == 1)
            {
                cout << endl;
                goto la3;
            }
            else
            {
                return;
            }
        }

        cout <<GREEN<< "You are succesfully login" <<RESET<< endl;
    }

    Event B;
la4:
    int k = 0;
    cout << endl;
    cout << "Here all events names :=" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < ev->size(); i = i + 2)
    {
        cout << left << setw(50) << ev[i] << " " << setw(50) << ev[i + 1] << endl;
    }
    cout << endl;
    cout << "Enter the name of the event you want to participate: ";
    cin.ignore();
    getline(cin, evname);
    cout << endl;

    for (int i = 0; i < 28; ++i)
    {
        for (auto person : info[club[i]])
        {
            if (person.second.name == evname)
            {
                B.rule1 = person.second.rule1;
                B.rule2 = person.second.rule2;
                B.rule3 = person.second.rule3;
                k = 1;
            }
        }
    }

    if (k == 0)
    {
        cout << "No event found, Please eneter correct name of the event" << endl;
        cout << "Enter 1 to re-enter or 0 to leave: ";
        int b;
        cin >> b;
        cout << endl;
        goto la4;
    }

    cout << "Rules for this event is as below " << endl;
    cout << "--------------------------------" << endl;
    cout << B.rule1 << endl;
    cout << B.rule2 << endl;
    cout << B.rule3 << endl;
    cout << endl;

    cout << "Are you still want to join this event, Please enter Y|N: ";
    char t;
    cin >> t;

    if (t == 'Y')
    {
        cout <<GREEN<< "You registered succesfully for " << evname <<RESET<< endl;

        ofstream fout;
        fout.open(file_name, ios::app);
        fout << endl;
        fout << A.name << " " << A.contact << " " << A.emid << " " << uname << " " << A.password << " " << evname;
        fout.close();

        data[evname][uname] = A;

        cout << endl;

        cout << "Do you want list of the person who is participated in this event" << endl;
        cout << "Enter Y|N: ";
        char t;
        cin >> t;
        cout << endl;

        if (t == 'Y')
        {
            cout <<BOLD_BLUE<< "--------------------------------------------------" <<RESET<< endl;
            cout << left << setw(20) <<BRIGHT_CYAN<< "Participate Name " << setw(20) << "Participate Username " <<RESET<< endl;
            cout <<BOLD_BLUE<< "--------------------------------------------------" <<RESET<< endl;
            for (auto person : data[evname])
            {
                cout << left << setw(20) << person.first << setw(20) << person.second.name << endl;
            }
            cout <<BOLD_BLUE<< "--------------------------------------------------" <<RESET<< endl;
        }

        cout << "Do you want list of the events name in which you participate" << endl;
        cout << "Enter Y|N : ";
        cin >> t;
        cout << endl;

        int n = 1;
        if (t == 'Y')
        {
            cout << "You Participed in those group:- " << endl;
            cout << "-------------------------------" << endl;
            for (int i = 0; i < ev->size(); ++i)
            {
                auto person = data[ev[i]].find(uname);
                if (person != data[ev[i]].end())
                {
                    cout << n << ". " << ev[i] << endl;
                    n++;
                }
            }
            cout << "-------------------------------" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Press 1 to participate in any other event or 0 to leave: ";
        int k;
        cin >> k;
        if (k == 0)
        {
            return;
        }
        else
        {
            cout << endl;
            goto la4;
        }
    }
}

void mj_event(){
    cout<<BRIGHT_MEGANTA<<"There is three major event conducted by clubs and committiees"<<RESET<<endl;
    cout<<BOLD_BLUE<<"1.Synapse    2.iFest    3.Concours"<<RESET<<endl;

    cout<<"Synapse is DAIICT's annual college fest, unites global artists and creative minds to showcase unique collages, share" 
    <<"creative processes, and transforms into a vibrant night of live music, DJ performances, and dance parties, fostering creative" 
    <<"connections and celebrating artistic expression."<<endl;
    cout<<"It is spread across 4 days, from 22 Feb to 25 Feb."<<endl;

    cout<<"iFest is one of the most anticipated and acknowledged technical fest all over Gujarat. It is lauded for its"
    <<"versatile and wide ranging technical, social and non-technical events."<<endl
    <<" The event spans across 3 days from November 3 to November 5"<<endl;

    cout<<"Concours is the annual national sports fest. Concours facilitates a healthy competition among the students in nine different sports"
    <<"The central idea the fest is to ingrain vigour and honour in the students"<<endl;
    cout<<"It spans across 4 days from 26 October to 29 October."<<endl;

    unordered_map<string,unordered_map<string,mj_Event>> data;

    mj_Event A;
    
    A.day=1;
    A.info="Stage Play is a part of Theatric events. Immerse yourself in the world of stage plays. A theatrical experience"
    <<"that brings stories to life on a captivating stage";
    A.time="22:00 to 01:00";
    A.venue="OAT";
    data["Synapse"]["Stage Play"] = A;

    A.day=1;
    A.info="Stand Up will feature two great artists: Nishant Suri and Gurleen Pannu. The performances will be a mixture of clever"
    <<"storytellying, witty one liner and spontaneous interactions which will be memorable.";
    A.time="20:00 to 21:30";
    A.venue="OAT";
    data["Synapse"]["Stand Up"] = A;

    A.day=1;
    A.info="Rampage is a fashion show. Immerse yourself in the world of style at our Fashion Expo. Explore the latest trends,"
    <<"designs, and glamorous runway showcases.";
    A.time="01:30 to 03:00";
    A.venue="OAT";
    data["Synapse"]["Rampage"]=A;

    A.day=2;
    A.info="MonoActe is a Theatric event. Witness the power of a single performer in MonoAct. A solo act that weaves a" 
    <<"compelling narrative and showcases the versatility of a lone artist.";
    A.time="09:00 to 12:00";
    A.venue="LT2";
    data["Synapse"]["MonoActe"]=A;

    A.day=2;
    A.info="Showdown is a dance event. Get ready to groove at our Hip-Hop Jam! A celebration of urban dance culture with beats" 
    <<"that will make you move.";
    A.time="09:00 to 15:00";
    A.venue="CEP Foyer";
    data["Synapse"]["Showdown"]=A;

    A.day=2;
    A.info="Tech Hunt is a technical event. Embark on a coding adventure where solving challenges unlocks the next code quest.";
    A.time="10:00 to 13:00";
    A.venue="Lab";
    data["Synapse"]["Tech Hunt"]=A;

    A.day=3;
    A.info="Code Mutants ia Tech event  to show off your programming skills, and solve as many problems as you can.";
    A.time="10:00 to 14:00";
    A.venue="LT2";
    data["Synapse"]["Code Mutants"]=A;

    A.day=3;
    A.info="Hunger Hikes is a fun event. A treasure hunt, but full of food. Showcase your knowledge about food";
    A.time="11:00 to 17:00";
    A.venue="Canteen";
    data["Synapse"]["Canteen"]=A;

    A.day=3;
    A.info="Concert by Antara Mitra will be magical. Get ready to feel the beat, the rhythm, and the soul of the music. ";
    A.time="20:00 to 23:00";
    A.venue="SAC";
    data["Synapse"]["Concert"]=A;

    A.day=4;
    A.info="Rap Battle,Use your frustration, thoughts, and feelings as a weapon and lay it out through a rap battle challenge";
    A.time="13:00 to 16:00";
    A.venue="Canteen";
    data["Synapse"]["Rap Battle"]=A;

    A.day=4;
    A.info="Naach, Hold your breath as dancers showcase the richness of our pristine heritage, pay homepage to time-honored traditions";
    A.time="15:00 to 18:00";
    A.venue="OAT";
    data["Synapse"]["Naach"]=A;

    A.day=4;
    A.info="Concert by Multi award winner, Amit Trivedi, Get ready to feel the beat, the rhythm, and the soul of the music.";
    A.time="20:00 to 23:00";
    A.venue="SAC";
    data["Synapse"]["Concert"]=A;

    A.day=1;
    A.info="iGanith is for math geeks who love playing with numbers at their fingertips, this is a chance to bring up your handy math skills.";
    A.time="14:00 to 16:00";
    A.venue="Lab";
    data["ifest"]["iGanith"]=A;

    A.day=1;
    A.info="iPapyrus,Present your innovative and mind-boggling research work at this event if you love ocean information.";
    A.time="17:00 to 19:00";
    A.venue="CEP-110";
    data["ifest"]["iPapyrus"]=A;

    A.day=1;
    A.info="iQuiz, Satiate your appetite for quizzes with i.Quiz, a tech-based quiz featuring staggering questions";
    A.time="19:00 to 20:30";
    A.venue="Lab";
    data["ifest"]["iQuiz"]=A;

    A.day=2;
    A.info="CSS Battle, The main objective of this event is visually replicating the target image in the least possible CSS code.";
    A.time="12:00 to 13:30";
    A.venue="Lab";
    data["ifest"]["CSS Battle"]=A;

    A.day=2;
    A.info="Chess64, Show us your smart chess moves and engage in brain-stimulating competitions against your opponents.";
    A.time="12:00 to 14:00";
    A.venue="CEP 004";
    data["ifest"]["Chess 64"]=A;

    A.day=2;
    A.info="Music Night, immerse yourself into the exciting music and show your enthusiasm on the stage.";
    A.time="23:00 to 01:00";
    A.venue="OAT";
    data["ifest"]["Music Night"]=A;

    A.day=2;
    A.info="iRide, Show your bicycle skills, but there is a twist, it is a slow cycling contest. Flaunt your balancing skills.";
    A.time="17:00 to 19:00";
    A.venue="Cafeteria";
    data["ifest"]["iRide"]=A;

    A.day=3;
    A.info="iPrompt, where you can flaunt your amazing imagination skills and then transfer it with the help of AI generative framework.";
    A.time="14:00 to 15:00";
    A.venue="Lab";
    data["ifest"]["iPrompt"]=A;

    A.day=3;
    A.info="The Open Box with Safin Hasan, join us to engage with a great personality and a source of inspiration.";
    A.time="11:00 to 12:00";
    A.venue="LT1";
    data["ifest"]["The Open Box"]=A;

    A.day=3;
    A.info="Blind C, Confident enough about your coding skills to be able to write them down blindfolded? (Well, not"
    <<"literally. But you’ll be screen blind!)";
    A.time="13:00 to 14:00";
    A.venue="Lab";
    data["ifest"]["Blind C"]=A;

    A.day=3;
    A.info="Concert by Asees Kaur, Get ready to feel the beat, the rhythm, and the soul of the music as soon as she gets on stage.";
    A.time="20:30 to 23:00";
    A.venue="SAC";
    data["ifest"]["Concert"]=A;


    A.day=1;
    A.info="Badminton Contest";
    A.time="20:00";
    A.venue="Badminton Court";
    data["Concours"]["Badminton"]=A;

    A.day=1;
    A.info="Volleyball Match";
    A.time="21:00";
    A.venue="SAC Ground";
    data["Concours"]["Volleyball"]=A;

    A.day=1;
    A.info="Football match";
    A.time="19:30";
    A.venue="SAC Ground";
    data["Concours"]["Football"]=A;

    A.day=1;
    A.info="Basketball Match";
    A.time="21:45";
    A.venue="Basketball Court";
    data["Concours"]["Basketball"]=A;

    A.day=2;
    A.info="Chess battle";
    A.time="10:00";
    A.venue="CEP 004";
    data["Concours"]["Chess"]=A;

    A.day=2;
    A.info="Cricket";
    A.time="07:30";
    A.venue="SAC Ground";
    data["Concours"]["Cricket"]=A;

    A.day=2;
    A.info="Table Tennis";
    A.time="13:00";
    A.venue="SAC-2";
    data["Concours"]["Table Tennis"]=A;

    A.day=3;
    A.info="Cricket";
    A.time="10:00";
    A.venue="SAC Ground";
    data["Concours"]["Cricket"]=A;

    A.day=3;
    A.info="Carrom";
    A.time="13:00";
    A.venue="SAC-2";
    data["Concours"]["Carrom"]=A;

    A.day=3;
    A.info="Football";
    A.time="18:30";
    A.venue="SAC Ground";
    data["Concours"]["Football"]=A;

    A.day=4;
    A.info="Cricket";
    A.time="07:30";
    A.venue="SAC Ground";
    data["Concours"]["Cricket"]=A;

    A.day=4;
    A.info="Chess";
    A.time="11:00";
    A.venue="CEP 004";
    data["Concours"]["Chess"]=A;

    A.day=4;
    A.info="Table Tennis";
    A.time="15:00";
    A.venue="SAC-2";
    data["Concours"]["Table Tennis"]=A;

    A.day=4;
    A.info="Volleyball";
    A.time="19:00";
    A.venue="SAC Ground";
    data["Concours"]["Volleyball"]=A;
}