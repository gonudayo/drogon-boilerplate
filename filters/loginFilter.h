/**
 *
 *  loginFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;

class loginFilter : public HttpFilter<loginFilter> {
 public:
  loginFilter() {}
  void doFilter(const HttpRequestPtr& req, FilterCallback&& fcb,
                FilterChainCallback&& fccb) override;
};
