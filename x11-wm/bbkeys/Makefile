# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.8.6
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A keygrabber for the Blackbox window manager

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5 bbkeys.bb.5
PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README
PLIST_FILES=	bin/bbkeys bin/bbkeysconf.pl \
		share/bbtools/bbkeys.bb share/bbtools/bbkeys.nobb

post-patch:
	@${PERL} -pi -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
