# New ports collection makefile for: bbpager
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbpager
PORTVERSION=	0.3.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbtools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pager for the Blackbox window manager

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bbpager share/bbtools/bbpager.bb \
		share/bbtools/bbpager.nobb share/bbtools/README.bbpager

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
