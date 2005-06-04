# New ports collection makefile for:	NovaWM
# Date created:				20 June 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	novawm
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	NovaWM-${PORTVERSION}_alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A window manager for X, developed with speed, size, and style in mind

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	INCLUDES=-I${X11BASE}/include \
		CXXFLAGS="${CXXFLAGS} -D_WIN_GNOME_SUPPORT" \
		novawm_LDFLAGS=-L${X11BASE}/lib

PLIST_FILES=	bin/novawm
.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog INSTALL README TODO
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

pre-clean:
	@-if [ -e ${WRKSRC}/src/xpm/.xvpics ]; then \
	    ${CHMOD} -R +w ${WRKSRC}/src/xpm/.xvpics 2>/dev/null; \
	fi
	@-if [ -e ${WRKSRC}/.xvpics ]; then \
	    ${CHMOD} -R +w ${WRKSRC}/.xvpics 2>/dev/null; \
	fi

.include <bsd.port.mk>
