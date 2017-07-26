#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP


class FreeGo {
    static FreeGo* instance_;

public:
    static FreeGo* instance();
    void init();
    boost::log::sources::severity_logger< boost::log::trivial::severity_level > lg;
private:

}; // class end

#define FREEGO_TRACE BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::trace)
#define FREEGO_DEBUG BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::debug)
#define FREEGO_INFO  BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::info)
#define FREEGO_WARN  BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::warning)
#define FREEGO_ERROR BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::error)
#define FREEGO_FATAL BOOST_LOG_SEV(FreeGo::instance()->lg, boost::log::trivial::fatal)
#endif // FILELOGGER_HPP