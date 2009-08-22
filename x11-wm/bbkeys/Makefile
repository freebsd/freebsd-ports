# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.9.1
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A keygrabber for the Blackbox window manager

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_PERL5=	yes
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags xft`" \
		LDFLAGS="`pkg-config --libs xft`"

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5
PORTDOCS=	AUTHORS BUGS ChangeLog LICENSE NEWS README TODO

PLIST_FILES=	bin/bbkeys %%DATADIR%%/bbkeysrc %%DATADIR%%/defaultStyle
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's#: install-docDATA#:#g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
