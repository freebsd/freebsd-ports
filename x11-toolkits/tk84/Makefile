# New ports collection makefile for:	tk8.0
# Version required:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id$
#

DISTNAME=	tk8.0
PKGNAME=	tk-8.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/ 

MAINTAINER=	jkh@Freebsd.ORG

LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

# This is totally vile and gross, but using something like BUILD_DEPENDS
# instead for this would cause a gratuitous rebuild/reinstall for what is
# really one of those "I just need some of your bits" cases."
pre-configure:
	@if [ ! -d ${PORTSDIR}/lang/tcl80 ]; then \
	  echo "Sorry, this port only works when ${PORTSDIR}/lang/tcl80 is also"; \
	  echo "available.  Please correct this problem and try again."; \
	  exit 1; \
	fi
	@echo Unpacking and configuring tcl80 sources...
	@cd ${PORTSDIR}/lang/tcl80 && make configure ECHO_MSG="echo >/dev/null"

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
