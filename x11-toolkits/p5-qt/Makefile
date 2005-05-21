# ex:ts=8
# Ports collection makefile for:	p5-qt
# Date created:			Mar 17, 2004
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.008
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	Qt/:cpan \
			perlqt/:sf
PKGNAMEPREFIX=	p5-
DISTNAME=	PerlQt-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:cpan \
		${DISTNAME}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of Perl bindings for the Qt toolkit

USE_GL=		yes
USE_QT_VER=	3
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/pqtapi bin/pqtsh bin/puic include/smoke.h \
		lib/libsmokeqt.a lib/libsmokeqt.so lib/libsmokeqt.so.3

MAN1=	puic.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Qt.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port needs Perl 5.6.0 or greater, please upgrade your Perl!"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Does not link on ia64"
.endif

post-configure:
	@cd ${CONFIGURE_WRKSRC}/PerlQt && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

post-install:
	@${FIND} ${PREFIX}/share/PerlQt-3 -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/PerlQt-3 -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/${PERL_ARCH}/Qt* -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/${PERL_ARCH}/Qt* -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/${PERL_ARCH}/auto/Qt -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/${PERL_ARCH}/auto/Qt -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.post.mk>
