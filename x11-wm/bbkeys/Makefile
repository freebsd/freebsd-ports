# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.9.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A keygrabber for the Blackbox window manager

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5
PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README
PLIST_FILES=	bin/bbkeys share/bbkeys/bbkeysrc share/bbkeys/defaultStyle

post-patch:
	@${PERL} -pi -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
