#include <fstream>
#include <filesystem>

class Logger 
{
public:
    enum Level {
        NONE, ERROR, INF, DEBUG, TRACE
    };

    enum Type {
        ALL, INIT, DOT1X, DRCOM
    };

    void log ( Type type, Level level, auto&&...args );

    Logger();

private:
    const std::filesystem::path logPath { std::filesystem::current_path() / "tmp" / "scutclient.log" };
    const std::filesystem::path oldPath { std::filesystem::current_path() / "tmp" / "scutclient.old.log" };
    void replaceOld() noexcept;
    std::ofstream file_d;
};
