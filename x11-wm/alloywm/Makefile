# New ports collection makefile for:	alloywm
# Date created:				2002-01-20
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	alloywm
PORTVERSION=	0.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.phatboydesigns.net/devel/

MAINTAINER=	trevor@FreeBSD.org

HAS_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
WANT_GTK=	yes
SCRIPTS=	${WRKSRC}/scriptdir

pre-configure:
	${FIND} ${WRKSRC} \( -name '*.in' -or -name configure \) -exec \
		${PERL} -pi -e 's:bash:sh:g ; \
		s:gtk-config:${GTK_CONFIG}:g' {} \;

pre-install:
	cd ${WRKSRC} && ${FIND} * -type f -perm 755 | cut -f 2 -d / | \
		${PERL} -pi -e "s:^:bin/:g" > ${PLIST}
	${FIND} ${SCRIPTS} \! -name '*in' -type f | \
		${PERL} -pi -e "s:^${SCRIPTS}:bin:g" >> ${PLIST}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${SCRIPTS}/* ${PREFIX}/bin
	${FIND} ${WRKSRC} -type f -perm 755 \
		-exec ${INSTALL_PROGRAM} {} ${PREFIX}/bin \;

.include <bsd.port.pre.mk>
.if defined(HAVE_GTK)
USE_GTK=yes
.endif
.include <bsd.port.post.mk>
