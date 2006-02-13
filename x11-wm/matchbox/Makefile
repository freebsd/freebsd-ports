# New ports collection makefile for:	matchbox
# Date created:				2002-07-14
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	matchbox
PORTVERSION=	0.9.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-window-manager/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:R}
DISTNAME=	${PORTNAME}-window-manager-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager suitable for low-resolution screens

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PORTDOCS=	${DOCS}
PLIST_FILES=	bin/matchbox-window-manager bin/matchbox-remote \
		etc/matchbox/kbdconfig
PLIST_DIRS=	etc/matchbox

DOCS=		AUTHORS ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3 || defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-standalone
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-standalone-xft
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/matchbox-remote ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/matchbox-window-manager ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/matchbox
	${INSTALL_DATA} ${WRKSRC}/data/kbdconfig ${PREFIX}/etc/matchbox
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
