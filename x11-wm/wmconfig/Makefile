# New ports collection makefile for:	wmconfig
# Whom:					Tommy Scheunemann <net@arrishq.org>
# Date created:		17 August 2003
#
# $FreeBSD$
#

PORTNAME=	wmconfig
PORTVERSION=	1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.org/downloads/

MAINTAINER=	net@arrishq.org
COMMENT=	Menu generation tool for X window managers

WRKSRC=		${WRKDIR}/${DISTNAME}
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc --mandir=${LOCALBASE}/man

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/wmconfig.1x ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/xterm ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/xmms ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/xearth ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/vim ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/sylpheed ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/rxvt ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/pine ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/mozilla ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/lynx ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/gv ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/gimp ${PREFIX}/etc/wmconfig
	@${INSTALL_DATA} ${WRKSRC}/samples/eterm ${PREFIX}/etc/wmconfig

.include <bsd.port.mk>
