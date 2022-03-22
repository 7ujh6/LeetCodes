#include <queue>
#include <unordered_set>
#include <string>
#include <thread>

using namespace std;

class HtmlParser {
  public:
  vector<string> getUrls(string url, bool flag) {
      if (flag)
        return vector<string>({"https://hellofresh.com", "www.ask.com",
        "http://lovelytoast.com"});
      else 
        return vector<string>({"www.ask.io", "www.plentyoffish.com", "https://hellofresh.com"});
  }
};

class Solution {
public:
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> toTraverse;
        unordered_set<string> explored;
        vector<string> crawled;
        int from = startUrl.find_last_of("//"), until = startUrl.find_last_of(".");
        from < 0 && from++, until = until < 0 ? startUrl.length() : until; 
        string seed = startUrl.substr(from, until);
        bool flag = true;
        
        auto webCrawl = [](unordered_set<string>& explored, queue<string>& toTraverse, HtmlParser& htmlParser, string& search, string& seed, bool flag) {
            
            vector<string> v = htmlParser.getUrls(search, true);
        
            for (const auto& e: v) { 
                int start = e.find_last_of("//"), end = e.find_last_of(".");
                start < 0 && start++, end = end < 0 ? e.length() : end; 
                
                if (e.substr(start, end) == seed && !explored.count(e)) toTraverse.push(e);
            }

            return explored.insert(search).second;
        };
        
        toTraverse.push(startUrl);
        
        for (;!toTraverse.empty();) {
            for (;explored.count(toTraverse.front()); toTraverse.pop());
            flag = !flag;
            std::thread instance(webCrawl, ref(explored), ref(toTraverse), ref(htmlParser), ref(toTraverse.front()), ref(seed), ref(flag));
            // std::thread instance(webCrawl, explored, toTraverse, htmlParser, toTraverse.front(), seed);
            instance.join();
        }
        
        crawled.insert(crawled.end(), explored.begin(), explored.end());
        return crawled;
    }
};

int main() {
    HtmlParser htmlParser;
    Solution solution;
    solution.crawl("www.ask.me", htmlParser);
    return 0;
}