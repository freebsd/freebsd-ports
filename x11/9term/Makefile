# New ports collection makefile for:    9term
# Version required:     1.6.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.4 1996/12/07 09:05:09 asami Exp $
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	erich@FreeBSD.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	/always_build_it:${PORTSDIR}/plan9/sam

NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
