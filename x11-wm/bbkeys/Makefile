# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A keygrabber for the Blackbox window manager

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GCC=	3.3+
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags xft`" \
		LDFLAGS="`pkg-config --libs xft`"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
