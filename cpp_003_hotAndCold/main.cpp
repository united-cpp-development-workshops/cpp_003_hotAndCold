#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <cmath>

void Print(int intervalInMs, bool lastInLine, const char* message)
{
  for (int i = 0; message[i] != '\0'; i++)
  {
    std::cout << message[i];
    std::this_thread::sleep_for(std::chrono::milliseconds(intervalInMs));
  }
  if (lastInLine)
  {
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void PrintSpedDownLinear(int intervalInMs, int maxIntervalInMs,
                         bool lastInLine, const char* message)
{
  int messageLen = 0;
  for (int i = 0; message[i] != '\0'; i++)
    messageLen++;
  int avgExtraInterval = (maxIntervalInMs - intervalInMs) / messageLen;
  int extraInterval = 0;
  for (int i = 0; i < messageLen; i++)
  {
    std::cout << message[i];
    std::this_thread::sleep_for(std::chrono::milliseconds(intervalInMs + extraInterval));
    extraInterval += avgExtraInterval;
  }
  if (lastInLine)
  {
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void PrintIntroMessage()
{
  Print(100, false, "#################### ");
  Print(150, false, "Hot N Cold");
  Print(100, true, " ####################");
  std::cout << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "-           ";
  Print(150, false, "You are Noah, Alex's friend.");
  std::cout << "           -" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "-           ";
  Print(150, false, "Please play his game");
  PrintSpedDownLinear(150, 350, false, " aaaaand");
  std::cout << "           -" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "-           ";
  Print(100, false, "SHOW HIM YOUR PSYCHIC POWERS");
  std::cout << "           -" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void PrintIntroConversation()
{
  PrintSpedDownLinear(150, 250, true, "Alex: Soooooooo...");
  Print(150, true, "Noah: Yeah?");
  PrintSpedDownLinear(100, 350, false, "Alex: We should... ");
  Print(100, true, "PLAY A GAME!");
  Print(100, false, "Noah: What kind of a game?");
  Print(500, false, " ");
  Print(100, false, "We don't even have any-");
  std::cout << std::endl;
  Print(100, true, "Alex: We don't need those fancy board games!");
  PrintSpedDownLinear(100, 250, true, "      We only need some...");
  PrintSpedDownLinear(150, 250, true, "      ImAGiNatIOoON.");
  Print(150, false, "Noah: Okay,");
  Print(500, false, " ");
  Print(150, false, "I was already bored ");
  PrintSpedDownLinear(150, 250, true, "soooo...");
  Print(100, true, "      What's on your mind?");
  Print(100, false, "Alex: I'll pick a number between 1 and 100,");
  std::cout << std::endl;
  Print(100, false, "      without telling you");
  Print(750, false, " ");
  Print(100, true, "of course.");
  Print(150, false, "      You will try to guess it in...");
  Print(500, false, " ");
  Print(250, true, "let's saaay,");
  Print(100, false, "      6 chances...");
  std::cout << std::endl;
  PrintSpedDownLinear(100, 350, false, "Noah: This is your...");
  Print(500, false, " ");
  PrintSpedDownLinear(150, 250, false, "ImAGiNatIOoON?");
  std::cout << std::endl;
  Print(100, true, "Alex: Yeah.");
  Print(100, false, "Noah: Also,");
  Print(500, false, " ");
  Print(150, false, "it's ridiculous!");
  Print(500, false, " ");
  PrintSpedDownLinear(100, 250, false, "There are 100 numbers, ");
  std::cout << std::endl;
  Print(150, true, "      how am I supposed to find it in just 6 tries?");
  Print(100, false, "Alex: Don't worry...");
  Print(500, false, " ");
  Print(150, true, "I'll give you some hints.");
  Print(100, true, "Noah: What kind of hints?");
  PrintSpedDownLinear(100, 250, true, "Alex: Do you know the term... \"hot and cold\"?");
  PrintSpedDownLinear(100, 250, true, "Noah: I heard of it, yeah.");
  Print(150, true, "Alex: What is it?");
  Print(100, false, "Noah: It's a song by Katy Perry!");
  std::cout << std::endl;
  Print(100, false, "Alex: Exactly!");
  std::cout << std::endl;
  Print(50, false, "Noah: Yeah?");
  std::cout << std::endl;
  Print(50, false, "Alex: No!");
  Print(500, false, " ");
  Print(150, false, "It is used in games to hint the direction.");
  std::cout << std::endl;
  Print(100, true, "Noah: Direction to what?");
  PrintSpedDownLinear(150, 250, true, "Alex: In our case... to picked number.");
  Print(100, true, "      If it's getting warmer and warmer...");
  Print(150, true, "      You're coming closer and closer.");
  Print(100, true, "      If it's getting colder and colder...");
  Print(150, true, "      You're not in the right direction.");
  Print(150, false, "Noah: I got it!");
  std::cout << std::endl;
  Print(100, false, "Alex: You do?");
  std::cout << std::endl;
  Print(100, true, "Noah: Yes.");
  Print(150, false, "Alex: We'll see...");
  std::cout << std::endl;
  Print(50, false, "      Oh,");
  Print(500, false, " ");
  Print(150, true, "one more thing...");
  Print(100, true, "Noah: What is it?");
  Print(150, true, "Alex: If you can't win at least 1 in 3 rounds...");
  PrintSpedDownLinear(150, 350, true, "      I WIN!!!");
  Print(150, true, "Noah: In your dreams...");
  Print(150, true, "Alex: Shall we?");
  Print(100, true, "Noah: Of course!");
}

int PickAndPrintNumber(int round)
{
  std::cout << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  
  if (round == 1)
  {
    Print(150, false, "Alex: All right. I will pick a number now");
    Print(500, true, "...");
    Print(150, false, "      Done!");
    Print(500, false, " ");
    Print(150, true, "Let's start.");
    Print(100, true, "Noah: I'm ready!");
    Print(100, false, "Alex: Win one,");
    Print(500, false, " ");
    Print(150, true, "win all!");
  }
  else if (round == 2)
  {
    Print(150, false, "Alex: All right. I'll pick the next number now");
    Print(500, true, "...");
    Print(150, true, "      Picked it!");
    Print(100, true, "Noah: Hope you pick a better number this time...");
    Print(100, true, "Alex: It's an interesting one!");
  }
  else
  {
    Print(150, false, "Alex: Picking the last number for you");
    Print(500, true, "...");
    Print(150, true, "      Okay!");
    Print(100, true, "Noah: I already have a guess!");
    Print(100, true, "Alex: Send it to me!");
  }
  std::random_device rdv;
  std::uniform_int_distribution<int> rnd(1, 100);
  return rnd(rdv);
}

void PrintStart()
{
  std::cout << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "-           ";
  Print(150, false, "You're in control, SMASH HIM");
  std::cout << "           -" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int TakeGuessedNumber()
{
  Print(150, false, "Noah: Is it... ");
  int guessedNumber = 0;
  while (!(std::cin >> guessedNumber))
  {
    Print(50, false, "Alex: Come ooon!");
    Print(500, false, " ");
    Print(150, true, "Be serious about it.");
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Print(150, false, "Noah: Sorry, is it... ");
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return guessedNumber;
}

bool EvaluateGuessedNumber(int distance, int pickedNumber, int iteration)
{
  if (distance == 0)
  {
    if (iteration == 0)
    {
      Print(150, false, "Alex: Are you...");
      Print(500, false, " ");
      Print(150, false, "a...");
      Print(500, false, " ");
      Print(150, false, "a...");
      Print(500, false, " ");
      Print(250, true, "PSYCHIC?");
      Print(150, false, "      It's impossible, but yes!");
      Print(500, false, " ");
      Print(150, false, "It was ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    else if (iteration < 2)
    {
      Print(100, false, "Alex: Perfect!");
      Print(500, false, " ");
      Print(50, false, "Yes!");
      Print(500, false, " ");
      Print(50, false, "Yes!");
      Print(500, false, " ");
      Print(150, true, "You've found it!");
      Print(150, false, "      You are very impressive!");
      Print(500, false, " ");
      Print(150, false, "I picked ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    else if (iteration < 3)
    {
      Print(150, false, "Alex: That was quick!");
      Print(500, false, " ");
      Print(150, true, "You've found it!");
      Print(150, false, "      You are good at it!");
      Print(500, false, " ");
      Print(150, false, "The number was ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    else if (iteration < 4)
    {
      Print(150, false, "Alex: It's correct!");
      Print(500, false, " ");
      Print(100, true, "You had two more guesses.");
      Print(150, false, "      You're fine!");
      Print(500, false, " ");
      Print(150, false, "The number was ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    else if (iteration < 4)
    {
      Print(150, false, "Alex: Yeah...");
      Print(500, false, " ");
      Print(100, true, "You did find the number I picked.");
      Print(150, false, "      That was close!");
      Print(500, false, " ");
      Print(150, false, "The number was ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    else
    {
      Print(200, false, "Alex: Finally!");
      Print(500, false, " ");
      Print(150, false, "You've found it.");
      Print(500, false, " ");
      Print(150, false, "It is ");
      std::cout << pickedNumber << "!" << std::endl;
    }
    return 1;
  }
  if (iteration == 0)
  {
    Print(150, false, "Alex: It's not right and,");
    Print(500, false, " ");
    Print(150, true, "not a suprise either.");
    Print(150, false, "      Okay,");
    Print(500, false, " ");
    Print(150, true, "here is your first hint!");
  }
  else if (iteration < 2)
  {
    PrintSpedDownLinear(150, 350, false, "Alex: False...");
    Print(500, false, " ");
    PrintSpedDownLinear(150, 250, true, "Unfortunately.");
    Print(150, false, "      Well,");
    Print(500, false, " ");
    Print(150, true, "you can do it!");
  }
  else if (iteration < 3)
  {
    PrintSpedDownLinear(150, 350, false, "Alex: Oh...");
    Print(500, false, " ");
    Print(150, true, "Not right again!");
    Print(150, false, "      Just think thoroughly,");
    Print(500, false, " ");
    Print(150, true, "we are not in a race!");
  }
  else if (iteration < 4)
  {
    PrintSpedDownLinear(150, 350, true, "Alex: No, no... Come ooon!");
    Print(100, true, "      Clear your head.");
  }
  else if (iteration < 5)
  {
    PrintSpedDownLinear(150, 350, true, "Alex: Pfff, you have one last chance!");
    Print(100, true, "      Use it carefully.");
    Print(100, true, "      Here comes your last hint!");
  }
  else
  {
    PrintSpedDownLinear(150, 350, true, "Alex: You failed!");
    Print(100, false, "      It was ");
    std::cout << pickedNumber;
    Print(150, true, ". It was not that hard!");
    PrintSpedDownLinear(150, 350, true, "Noah: Easy to say!");
  }
  return 0;
}

void PrintRoundWonConversation(int round, int winCount)
{
  switch (round)
  {
    case 1:
      PrintSpedDownLinear(150, 250, false, "Noah: Hahaha...");
      Print(500, false, " ");
      Print(150, false, "I already won at the first round!");
      std::cout << std::endl;
      PrintSpedDownLinear(100, 250, false, "Alex: Yeah, yeaah...");
      Print(500, false, " ");
      Print(150, true, "Its just luck!");
      Print(100, true, "Noah: I'll prove you it is not luck!");
      Print(150, true, "Alex: Win the next round and I will believe it.");
      Print(150, true, "Noah: Let me have it!");
      break;
    case 2:
      switch (winCount)
      {
        case 1:
          Print(200, true, "Noah: Yeaay...");
          Print(150, true, "Alex: Congratulations on your first win!");
          Print(100, false, "Noah: First?");
          Print(500, true, " ");
          Print(150, false, "      I thought it'd be over because I won");
          Print(500, false, " ");
          Print(150, true, "\"the\" game?");
          Print(100, false, "Alex: Yeah but, isn't it fun though?");
          std::cout << std::endl;
          Print(100, true, "Noah: No!");
          Print(150, true, "Alex: I said it is a game of 3 rounds... Please?");
          PrintSpedDownLinear(150, 250, true, "Noah: (sighs)... Go ahead!");
          break;
        default:
          Print(150, true, "Noah: You see...");
          Print(100, true, "Alex: I still don't believe it! There must be a trick.");
          PrintSpedDownLinear(150, 250, false, "      Or...");
          Print(500, false, " ");
          Print(150, true, "Are you CHEATING?");
          PrintSpedDownLinear(150, 250, true, "Noah: No, there is a trick!");
          Print(150, true, "      I'll tell you if I win the final round.");
          Print(150, false, "Alex: What is the trick?");
          Print(500, false, " ");
          Print(250, true, "TELL ME!");
          Print(150, true, "Noah: Only, if I win the last one...");
          break;
      }
      break;
    default:
      switch (winCount)
      {
        case 1:
          Print(100, true, "Noah: I knew I would win...");
          Print(150, true, "Alex: Even with extra hint... Just, barely!");
          Print(100, false, "Noah: You said if i could win only-");
          std::cout << std::endl;
          Print(100, true, "Alex: One of the rounds, you would win the game.");
          Print(150, true, "      Yes, I know that...");
          Print(100, false, "Noah: Tell it!");
          std::cout << std::endl;
          Print(100, false, "Alex: Tell what?");
          std::cout << std::endl;
          Print(150, true, "Noah: Tell me that I won and you lost.");
          Print(250, true, "Alex: Okay... You won.");
          Print(150, false, "Noah: And I lo-");
          std::cout << std::endl;
          Print(100, true, "Alex: And I lost.");
          Print(250, false, "Noah: Ha ha ha haaaa...");
          break;
        case 2:
          Print(200, true, "Noah: You see... I've learned it!");
          Print(150, false, "Alex: You got it-");
          std::cout << std::endl;
          Print(100, true, "Noah: I got it!");
          PrintSpedDownLinear(250, 500, true, "Alex: ...");
          Print(150, true, "Noah: What?");
          Print(150, true, "Alex: I picked easy numbers for you.");
          Print(150, true, "Noah: Liar!");
          break;
        default:
          Print(150, true, "Noah: The trick never let's me down.");
          Print(100, true, "Alex: Tell it now... You won all three rounds.");
          Print(150, true, "Noah: I'll tell you, don't worry.");
          Print(150, true, "Alex: I am listening...");
          Print(150, true, "Noah: Well... You should've figured it out already.");
          Print(250, true, "Alex: But, I didn't.");
          Print(150, true, "Noah: It is easy, listen:");
          Print(150, false, "      I always aim for the half, like ");
          Print(350, false, "aaa");
          Print(150, true, " 50.");
          Print(150, true, "Alex: And?");
          Print(150, true, "Noah: If you say higher, I guess the upper part's half.");
          Print(150, true, "      That way, I'll have at least 50% chance in the end.");
          PrintSpedDownLinear(150, 500, false, "Alex: That's...");
          Print(1000, false, " ");
          Print(150, true, "clever!");
          Print(150, false, "Noah: Like I am.");
          Print(500, false, " ");
          Print(150, true, "Thank you!");
          break;
      }
      break;
  }
}

void PrintHintConversation(int distance, int pickedNumber, int guessedNumber)
{
  bool shouldHigh = (pickedNumber - guessedNumber) > 0 ? true : false;
  if (distance < 5)
  {
    Print(100, true, "      You are burning up though!");
    Print(100, true, (shouldHigh ? "      Higher, higheeer!" : "      Lower, loooower!"));
  }
  else if (distance < 10)
  {
    Print(150, true, "      But it's really hot! I mean, really really hot.");
    Print(150, true, (shouldHigh ? "      Go little higher, bigger!" : "      Go little lower, smaller!"));
  }
  else if (distance < 20)
  {
    Print(100, true, "      Don't worry! It's hot.");
    Print(100, true, (shouldHigh ? "      Just go higher." : "      Just go lower."));
  }
  else if (distance < 30)
  {
    Print(150, true, "      Well, you are in a very warm environment mate.");
    Print(250, true, (shouldHigh ? "      Make it higher." : "      Make it lower."));
  }
  else if (distance < 40)
  {
    Print(100, true, "      By the way, it is warm.");
    Print(100, true, (shouldHigh ? "      Go high." : "      Go low."));
  }
  else if (distance < 50)
  {
    Print(100, true, "      And... It's neither warm nor cold!");
    Print(100, true, (shouldHigh ? "      Higher mate." : "      Lower mate."));
  }
  else if (distance < 60)
  {
    Print(150, true, "      It's chill out here, take me somewhere hot!");
    Print(250, true, (shouldHigh ? "      And higher." : "      And lower."));
  }
  else if (distance < 70)
  {
    Print(150, true, "      Very chill... I get goosebumps!");
    Print(150, true, (shouldHigh ? "      Go up." : "      Go down."));
  }
  else if (distance < 80)
  {
    Print(100, true, "      I hate cold. It's cold out here!");
    Print(250, true, (shouldHigh ? "      Let's go higher!" : "      Let's go lower!"));
  }
  else if (distance < 90)
  {
    Print(100, true, "      This is like an unbearable cold!");
    Print(250, true, (shouldHigh ? "      GO HIGH!" : "      GO LOW!"));
  }
  else
  {
    Print(250, true, "      It  t's s so soo   frrr fre ezin nng he rr he r re!");
    Print(250, true, (shouldHigh ? "      Gggoo hh i hih ggh e rrrr!" : "      Gggoo  l low lowerr!"));
  }
}

void PrintRoundEndConversation(int round, int winCount)
{
  std::cout << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  
  Print(150, false, "Alex: Round ");
  std::cout << round;
  Print(150, true, " has ended!");
  PrintSpedDownLinear(150, 500, false, "Noah: And I have ");
  std::cout << winCount;
  Print(150, true, " points!");
}

void PrintEndGameConversation(int winCount)
{
  std::cout << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  switch (winCount)
  {
    case 0:
      Print(150, true, "Alex: Even with the extra hint, hahaha ha...");
      Print(100, true, "      Huh, you're just bad at these things eh?");
      PrintSpedDownLinear(150, 350, true, "Noah: It was a stupid game after all...");
      Print(100, false, "      Let's play some Fortnite!");
      std::cout << std::endl;
      Print(100, true, "Alex: Agreed!");
      Print(100, true, "      But you are really bad.");
      Print(100, true, "Noah: Shut up!");
      break;
    case 1:
      Print(150, true, "Alex: Yes you did win after all...");
      Print(100, true, "Noah: I did!");
      Print(100, true, "Alex: Should we go another round?");
      Print(100, true, "Noah: Definitly not!");
      Print(250, true, "Alex: Is it that-");
      Print(100, true, "Noah: Yes!");
      Print(250, true, "Alex: Hmmm...");
      Print(150, true, "Noah: I'll go get some sleep now.");
      Print(100, true, "      It's late, you should do the same.");
      Print(150, true, "Alex: I'll perfect my game, thanks.");
      Print(100, true, "Noah: You perfect my #$@*#%$!");
      Print(150, true, "Alex: Hey, you're being rude!");
      Print(150, true, "Noah: Yea, yea...");
      break;
    case 2:
      Print(150, true, "Alex: You did surprisingly well.");
      Print(100, true, "Noah: Why is it surprising to you, may I ask?");
      Print(150, false, "Alex: You know... You are not that-");
      std::cout << std::endl;
      Print(100, false, "Noah: Clever?");
      Print(500, false, " ");
      Print(100, true, "Intelligent?");
      PrintSpedDownLinear(100, 250, false, "Alex: More like...");
      Print(500, false, " ");
      Print(250, true, "Capable.");
      Print(100, true, "Noah: Well, now you know!");
      Print(1000, true, "Alex: ...");
      Print(1000, true, "Noah: ...");
      Print(150, true, "Alex: I'll order some pizza, you want one?");
      Print(150, true, "Noah: Yeah, a large Margherita!");
      Print(100, true, "Alex: Then get yourself one.");
      Print(150, true, "Noah: You are a bad person Alex!");
      break;
    default:
      Print(150, true, "Alex: Well done really!");
      Print(100, true, "Noah: This was the easiest game I ever played!");
      Print(100, true, "Alex: It was not that easy, you just found its bugs.");
      Print(150, true, "Noah: I found those bugs,");
      Print(150, true, "      That's what I can be.");
      Print(100, true, "Alex: No, no, you can't, you are not!");
      Print(150, true, "Noah: I am whatever Gotham needs me to be.");
      Print(1000, false, " ");
      Print(100, true, "     Call it in!");
      Print(1000, true, "Alex: ...");
      Print(150, false, "      A hero,");
      Print(500, false, " ");
      Print(150, true, "not a hero we deserved but the hero we needed.");
      Print(150, true, "      Nothing less than a knight, shining.");
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Noah: ..." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Alex: They'll hunt you." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Noah: You'll hunt me." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "      You'll condemn me, set the dogs on me." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "      ...because it't what needs to happen." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "      Because sometimes the truth isn't good enough..." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "      ...sometimes people deserve more." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "      Sometimes people deserve to have their faith rewarded." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Alex2: Noah? Noah! Why is he running, Dad?" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Alex1: Because we have to chase him." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Alex2: He didn't do anything wrong." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "Alex1: Because..." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "       ...he's the hero Gotham deserves, but not the one" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "       it needs right now. So, we'll hunt him, because" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      std::cout << "       he can take it. Because he's not our hero." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      Print(150, true, "Alex: He's a silent guardian.");
      Print(150, true, "      A watchful protector.");
      PrintSpedDownLinear(250, 500, true, "      A Dark Knight.");
      break;
  }
  std::cout << std::endl;
  Print(100, false, "#################### ");
  Print(150, false, "Hot N Cold");
  Print(100, true, " ####################");
  std::cout << std::endl;
  Print(100, true, "Emrecan: The game is basically over but,");
  Print(150, true, "         I want to say this...");
  Print(150, true, "Bjarne:: What is it this time?");
  Print(200, true, "Emrecan: C++ is so fun, I like it!");
  for (int i = 0; i < 10; i++)
  {
    std::cout << "         ";
    Print(100, true, "I like it! I like it!");
  }
  Print(250, true, "Bjarne:: That's good.");
}

int main() {
  PrintIntroMessage();
  PrintIntroConversation();
  int winCount = 0;
  int round = 1;
  while (round < 4)
  {
    int pickedNumber = PickAndPrintNumber(round);
    PrintStart();
    if (round == 3 && winCount == 0)
    {
      PrintSpedDownLinear(150, 250, true, "Alex: Since this is your last round, aaand...");
      Print(150, false, "      You are doing terrible.");
      Print(500, false, " ");
      Print(150, true, "I'll give you an");
      Print(250, true, "      ExXtRAa HIiInT!");
      Print(150, false, "Noah: I don't need it!");
      std::cout << std::endl;
      Print(100, true, "Alex: You definitly do! And it is...");
      Print(100, false, "      The number I picked is an");
      Print(500, false, " ");
      Print(150, true, ((pickedNumber % 2) ? "odd number!" : "even number!"));
    }
    int prevDistance = -1;
    for (int i = 0; i < 6; i++)
    {
      int guessedNumber = TakeGuessedNumber();
      int distance = std::abs(pickedNumber - guessedNumber);
      if(prevDistance != -1 && prevDistance < distance)
      {
        Print(150, true, "Alex: Are you not listening? Listen my hints!");
        Print(150, true, "Noah: Ooh, sorry I wasn't giving attention.");
        Print(150, true, "Alex: You better do or you'll lose!");
      }
      else if (prevDistance == distance)
      {
        Print(100, true, "Alex: It's the same guess Noah! You can't...");
        Print(150, false, "      Just, not.. It's not...");
        Print(500, false, " ");
        Print(100, true, "that, it's false!");
        Print(150, true, "Noah: I was just checking you!");
        Print(150, true, "Alex: I bet you were...");
      }
      else if (EvaluateGuessedNumber(distance, pickedNumber, i))
      {
        winCount++;
        PrintRoundWonConversation(round, winCount);
        break;
      }
      if (i != 5)
        PrintHintConversation(distance, pickedNumber, guessedNumber);
      prevDistance = distance;
    }
    PrintRoundEndConversation(round, winCount);
    round++;
  }
  PrintEndGameConversation(winCount);
}
