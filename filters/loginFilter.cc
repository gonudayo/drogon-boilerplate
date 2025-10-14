/**
 *
 *  loginFilter.cc
 *
 */

#include "loginFilter.h"

using namespace drogon;

void loginFilter::doFilter(const HttpRequestPtr& req, FilterCallback&& fcb,
                           FilterChainCallback&& fccb) {
  // Edit your logic here
  LOG_DEBUG << "Filter is active";
  if (1) {
    // Passed
    fccb();
    return;
  }
  // Check failed
  auto res = drogon::HttpResponse::newHttpResponse();
  res->setStatusCode(k500InternalServerError);
  fcb(res);
}
